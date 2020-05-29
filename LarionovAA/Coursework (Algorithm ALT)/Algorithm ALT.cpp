
#include <iostream>
#include <vector>

#define INFINITE 10000


class Node
{
public:
	// Возможность прохода -> 1 - да; 0 - нет
	int passage;
	// Координаты вершины
	int x = 0;
	int y = 0;
	// Оценочная функция -> f = g + h
	int f = 0;
	// Расстояние от начальной вершины
	int g = 0;
	// Эвристическая функция
	int h = 0;
	// Вершина, из которой произошел переход
	Node* parent = nullptr;
	// Расстояния до ориентиров (количество - 4)
	// рассчитывается на этапе препроцессинга
	int l[4] = { 0 };
public:
	Node(const int x, const int y, const int passage) 
	{
		this->x = x;
		this->y = y;
		this->passage = passage;
	};
	~Node() {};
};


Node* extract_next_node_p(std::vector <Node*>& setNode, const int numberLand)
{
	Node* buffer = nullptr;
	int index = 0;
	int minValue = INFINITE;

	for (size_t i = 0; i < setNode.size(); i++)
	{
		if (setNode[i]->l[numberLand] < minValue)
		{
			index = i;
			minValue = setNode[i]->l[numberLand];
		}
	}

	buffer = setNode[index];
	setNode.erase(setNode.begin() + index);

	return buffer;
}

std::vector <Node*> get_neighbour(std::vector <Node*> graph, const int lenght, const int width, const Node* node)
{
	std::vector <Node*> buffer;
	
	if (((node->y + 1) >= 0 && (node->y + 1) < lenght) && (node->x >= 0 && node->x < width))
	{
		size_t indexUp = (node->y + 1) * width + node->x;

		if (graph[indexUp]->passage == 1)
		{
			buffer.push_back(graph[indexUp]);
		}
	}

	if (((node->y - 1) >= 0 && (node->y - 1) < lenght) && (node->x >= 0 && node->x < width))
	{
		size_t indexDown = (node->y - 1) * width + node->x;

		if (graph[indexDown]->passage == 1)
		{
			buffer.push_back(graph[indexDown]);
		}
	}

	if ((node->y >= 0 && node->y < lenght) && ((node->x + 1) >= 0 && (node->x + 1) < width))
	{
		size_t indexRight = node->y * width + (node->x + 1);

		if (graph[indexRight]->passage == 1)
		{
			buffer.push_back(graph[indexRight]);
		}
	}

	if ((node->y >= 0 && node->y < lenght) && ((node->x - 1) >= 0 && (node->x - 1) < width))
	{
		size_t indexLeft = node->y * width + (node->x - 1);

		if (graph[indexLeft]->passage == 1)
		{
			buffer.push_back(graph[indexLeft]);
		}
	}
	
	return buffer;
}

bool check_visited_node(std::vector <Node*> setNode, Node* node)
{
	bool result = false;

	for (size_t i = 0; i < setNode.size(); i++)
	{
		if (setNode[i] == node)
		{
			result = true;
			break;
		}
	}

	return result;
}

void search_way_from_landmark(std::vector <Node*>& graph, const int lenght, const int width, const int indexLand, const int numberLand)
{
	std::vector <Node*> nextNodes;
	std::vector <Node*> visitedNodes;

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (i == indexLand)
		{
			graph[i]->l[numberLand] = 0;
			continue;
		}
		graph[i]->l[numberLand] = INFINITE;
	}

	nextNodes.push_back(graph[indexLand]);

	while (nextNodes.empty() != true)
	{
		Node* current = extract_next_node_p(nextNodes, numberLand);

		visitedNodes.push_back(current);

		std::vector <Node*> neighbours = get_neighbour(graph, lenght, width, current);

		for (size_t i = 0; i < neighbours.size(); i++)
		{
			bool result = check_visited_node(visitedNodes, neighbours[i]);

			if (result == false)
			{
				int tempDistance = current->l[numberLand] + 1;

				if (tempDistance < neighbours[i]->l[numberLand])
				{
					neighbours[i]->l[numberLand] = tempDistance;
				}

				nextNodes.push_back(neighbours[i]);
			}
		}
	}

	return;
}

void preprocess(int graph[][9], std::vector <Node*>& convertedGraph,  const int lenght, const int width)
{
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Node* node = nullptr;
			if (graph[i][j] == 1)
			{
				node = new Node(j, i, 1);
			}
			if (graph[i][j] == 0)
			{
				node = new Node(j, i, 0);
			}
			convertedGraph.push_back(node);
		}
	}

	search_way_from_landmark(convertedGraph, lenght, width, (0 * width + 0), 0);
	search_way_from_landmark(convertedGraph, lenght, width, (0 * width + 8), 1);
	search_way_from_landmark(convertedGraph, lenght, width, (8 * width + 0), 2);
	search_way_from_landmark(convertedGraph, lenght, width, (8 * width + 8), 3);

	return;
}

int get_max(const int oneDist, const int twoDist)
{
	int buffer = 0;

	if (oneDist > twoDist)
	{
		buffer = oneDist - twoDist;
	}
	else
	{
		buffer = twoDist - oneDist;
	}

	return buffer;
}

int estimate_dist(std::vector <Node*> graph, const Node* current, const Node* destination)
{
	int result = 0;

	for (int i = 0; i < 4; i++)
	{
		int buffer = get_max(current->l[i], destination->l[i]);

		if (buffer > result)
		{
			result = buffer;
		}
	}

	return result;
}

Node* extract_next_node_s(std::vector <Node*>& setNode)
{
	Node* buffer = nullptr;
	int index = 0;
	int minValue = INFINITE;

	for (size_t i = 0; i < setNode.size(); i++)
	{
		if (setNode[i]->f < minValue)
		{
			index = i;
			minValue = setNode[i]->f;
		}
	}

	buffer = setNode[index];
	setNode.erase(setNode.begin() + index);

	return buffer;
}

void find_way_between_two_nodes(std::vector <Node*>& graph, const int lenght, const int width, const int launch, const int destination)
{
	std::vector <Node*> nextNodes;
	std::vector <Node*> visitedNodes;

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (graph[i]->passage == 1)
		{
			if (i == launch)
			{
				graph[i]->g = 0;
				graph[i]->h = estimate_dist(graph, graph[i], graph[destination]);
				graph[i]->f = graph[i]->g + graph[i]->h;
				continue;
			}
			graph[i]->g = INFINITE;
			graph[i]->h = estimate_dist(graph, graph[i], graph[destination]);
			graph[i]->f = graph[i]->g + graph[i]->h;
		}
		if (graph[i]->passage == 0)
		{
			graph[i]->g = INFINITE;
			graph[i]->h = INFINITE;
			graph[i]->f = graph[i]->g + graph[i]->h;
		}
	}

	nextNodes.push_back(graph[launch]);

	while (nextNodes.empty() != true)
	{
		Node* current = extract_next_node_s(nextNodes);

		if (current == graph[destination])
		{
			break;
		}

		visitedNodes.push_back(current);

		std::vector <Node*> neighbours = get_neighbour(graph, lenght, width, current);

		for (size_t i = 0; i < neighbours.size(); i++)
		{
			bool result = check_visited_node(visitedNodes, neighbours[i]);

			if (result == false)
			{
				int tempDistance = current->g + 1;

				if (tempDistance < neighbours[i]->g)
				{
					neighbours[i]->g = tempDistance;
					neighbours[i]->f = neighbours[i]->g + neighbours[i]->h;
					neighbours[i]->parent = current;
				}

				nextNodes.push_back(neighbours[i]);
			}
		}
	}

	return;
}

void print_path(std::vector <Node*> graph, const int destination)
{
	std::vector <Node*> path;
	Node* current = graph[destination];

	while (current != nullptr)
	{
		path.push_back(current);
		current = current->parent;
	}

	std::cout << std::endl;

	for (size_t i = 0; i < path.size(); i++)
	{
		std::cout << "x=" << path[i]->x << "," << "y=" << path[i]->y;

		if (i != (path.size() - 1))
		{
			std::cout << " <- ";
		}
	}

	std::cout << " start";
	std::cout << std::endl;

	return;
}

void search_way(int graph[][9], const int lenght, const int width, const int launch, const int destination)
{
	std::vector <Node*> graphNodes;

	preprocess(graph, graphNodes, lenght, width);

	find_way_between_two_nodes(graphNodes, lenght, width, launch, destination);

	print_path(graphNodes, destination);

	return;
}


int main()
{
	const int lenght = 9;
	const int width = 9;

	//Порядковые номера вершин находятся как (line * width + column) -> нужны для функции поиска кратчайшего пути
	//(line,column) - координаты вершины -> line >= 0 && line < lenght; column >= 0 && column < width
	int grid[lenght][width] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1},
	};

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//60 - порядковый номер начальной вершина 
	// 9 - порядковый номер конечной вершины
	search_way(grid, lenght, width, 60, 8);

	return 0;
}


#include <iostream>

#define NUMBER_NODE 6
#define INFINITE 10000

class Node
{
public:
	int neighborWay[NUMBER_NODE] = { 0 };
	int distance = 0;
	int number = 0;
public:
	Node(const int* linkArray, const int number)
	{
		for (int i = 0; i < NUMBER_NODE; i++)
		{
			if (linkArray[i] >= 0)
			{
				neighborWay[i] = linkArray[i];
			}
		}
		this->number = number + 1;
	};
	~Node() {};
};

class Graph
{
private:
	int counter = 0;
	int distanceMap[NUMBER_NODE] = { 0 };
	Node* previous[NUMBER_NODE] = { nullptr };
	Node* nodes[NUMBER_NODE] = { nullptr };
private:
	void add_node_in_nodes(Node* node);
	void add_node_in_array(Node* (*array), Node* node);
	bool check_full_array(Node* (*array));
	bool check_visited_node(Node* (*array), Node* node);
	Node* extract_min_node(Node* (*array));
	void output_path(const int launch, const int destination);
public:
	void search_way(const int launch, const int destination);
	int add_node(const int* linkArray);
	void clear_graph();
	void print_graph();
public:
	Graph() {};
	~Graph() {};
};

void Graph::add_node_in_nodes(Node* node)
{
	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (nodes[i] == nullptr)
		{
			nodes[i] = node;
			break;
		}
	}

	return;
}

void Graph::add_node_in_array(Node* (*array), Node *node)
{
	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (array[i] == nullptr)
		{
			array[i] = node;
			break;
		}
	}

	return;
}

bool Graph::check_full_array(Node* (*array))
{
	bool result = false;

	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (array[i] != nullptr)
		{
			result = true;
		}
	}

	return result;
}

bool Graph::check_visited_node(Node* (*array), Node* node)
{
	bool result = false;

	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (array[i] == node)
		{
			result = true;
			break;
		}
	}

	return result;
}

Node* Graph::extract_min_node(Node* (*array))
{
	Node* desiredNode = nullptr;
	int indexNode = -1;
	int minValue = INFINITE;

	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if ((array[i] != nullptr) && (array[i]->distance < minValue))
		{
			desiredNode = array[i];
			indexNode = i;
			minValue = array[i]->distance;
		}
	}

	if (indexNode != -1)
	{
		array[indexNode] = nullptr;
	}

	return desiredNode;
}

void Graph::output_path(const int launch, const int destination)
{
	std::cout << std::endl << "Minimum distance-map from your start node:" << std::endl;

	for (int i = 0; i < NUMBER_NODE; i++)
	{
		std::cout << distanceMap[i] << " ";
	}

	std::cout << std::endl << "Path from your start node to destination node:" << std::endl;

	int path[NUMBER_NODE] = { 0 };
	int counter = 0;

	path[counter] = destination;
	counter++;

	int buffer = previous[path[counter - 1] - 1]->number;

	while (buffer != launch)
	{
		path[counter] = buffer;
		counter++;
		buffer = previous[path[counter - 1] - 1]->number;
	}

	path[counter] = launch;
	counter++;

	for (int i = (NUMBER_NODE - 1); i >= 0; i--)
	{
		if (path[i] != 0)
		{
			std::cout << path[i];
			if (i != 0)
			{
				std::cout << " -> ";
			}
		} 
	}

	std::cout << std::endl;

	return;
}


void  Graph::search_way(const int launch, const int destination)
{
	if (counter < NUMBER_NODE)
	{
		std::cout << "Write all nodes!" << std::endl;
		return;
	}

	if ((launch < 1 || launch > NUMBER_NODE) || (destination < 1 || destination > NUMBER_NODE))
	{
		std::cout << "Incorrect nodes!" << std::endl;
		return;
	}

	Node* nextNodes[NUMBER_NODE] = { nullptr };

	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (i == (launch - 1))
		{
			distanceMap[i] = 0;
			nodes[i]->distance = 0;
		}
		else
		{
			distanceMap[i] = INFINITE;
			nodes[i]->distance = INFINITE;
		}
		add_node_in_array(nextNodes, nodes[i]);
		previous[i] = nodes[launch - 1];
	}

	Node* visitedNodes[NUMBER_NODE] = { nullptr };

	bool full = check_full_array(nextNodes);

	while (full == true)
	{
		Node* currentNode = extract_min_node(nextNodes);

		for (int i = 0; i < NUMBER_NODE; i++)
		{
			if (currentNode->neighborWay[i] > 0)
			{
				bool result = check_visited_node(visitedNodes, nodes[i]);

				if (result == false)
				{
					int tempDistance = currentNode->distance + currentNode->neighborWay[i];

					if (tempDistance < distanceMap[i])
					{
						distanceMap[i] = tempDistance;
						nodes[i]->distance = tempDistance;
						previous[i] = currentNode;
					}
				}
			}
		}

		add_node_in_array(visitedNodes, currentNode);

		full = check_full_array(nextNodes);
	}

	output_path(launch, destination);

	return;
}

int Graph::add_node(const int* linkArray)
{
	if (counter == NUMBER_NODE)
	{
		return 0;
	}

	Node* newNode = new Node(linkArray, counter);

	add_node_in_nodes(newNode);

	counter++;

	return 1;
}

void Graph::clear_graph()
{
	for (int i = 0; i < NUMBER_NODE; i++)
	{
		delete nodes[i];
		nodes[i] = nullptr;
		counter--;
	}

	return;
}

void Graph::print_graph()
{
	for (int i = 0; i < NUMBER_NODE; i++)
	{
		if (nodes[i] != nullptr)
		{
			for (int j = 0; j < NUMBER_NODE; j++)
			{
				printf("%3i", nodes[i]->neighborWay[j]);
			}
		}
		std::cout << std::endl;
	}

	return;
}


int main()
{
	Graph One;

	//Adding
	int arrayOne[NUMBER_NODE] = { 0, 2, 5, 7, 7, 10 };
	One.add_node(arrayOne);

	int arrayTwo[NUMBER_NODE] = { 2, 0, 6, 3, 4, 8 };
	One.add_node(arrayTwo);

	int arrayThree[NUMBER_NODE] = { 5, 6, 0, 15, 3, 1 };
	One.add_node(arrayThree);

	int arrayFour[NUMBER_NODE] = { 7, 3, 15, 0, 8, 11, };
	One.add_node(arrayFour);

	int arrayFive[NUMBER_NODE] = { 7, 4, 3, 8, 0, 4 };
	One.add_node(arrayFive);

	int arraySix[NUMBER_NODE] = { 10, 8, 1, 11, 4, 0 };
	One.add_node(arraySix);

	One.print_graph();

	//Search short way between nodes
	One.search_way(1, 6);

	return 1;
}

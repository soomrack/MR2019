#include <iostream>
#define SIZE 6
#define INFINITY 10000

class Graph
{
public:
	int communications[SIZE][SIZE];
public:
	Graph(int array[SIZE][SIZE]);
	~Graph() {};
	void print_min_route(int start, int finish);
private:
	int* find_min_route_deikstra(int start, int finish);
};

Graph::Graph(int array[SIZE][SIZE])
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			communications[row][col] = array[row][col];
		}
	}
}

int* Graph::find_min_route_deikstra(int start, int finish)
{
	int min_distances[SIZE];
	bool visited_nodes[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		min_distances[i] = INFINITY;
		visited_nodes[i] = false;
	}
	min_distances[start] = 0;
	int nearest_node_index = start;
	int nearest_node_distance = 0;
	while (nearest_node_index < INFINITY)
	{
		nearest_node_index = INFINITY;
		nearest_node_distance = INFINITY;
		//находим ближайшую вершину, которую еще не обошли
		for (int i = 0; i < SIZE; i++)
		{
			if (!visited_nodes[i] && min_distances[i] < nearest_node_distance)
			{
				nearest_node_distance = min_distances[i];
				nearest_node_index = i;
			}
		}
		//обновляем минимальные расстояния до соседей текущей вершины
		if (nearest_node_index != INFINITY)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (communications[nearest_node_index][i] > 0)
				{
					if ((nearest_node_distance + communications[nearest_node_index][i]) < min_distances[i])
						min_distances[i] = nearest_node_distance + communications[nearest_node_index][i];
				}
			}
			visited_nodes[nearest_node_index] = true;
		}
	}
	//восстановление минимального пути
	int* min_route = new int[SIZE + 1];
	int amount_of_visited_nodes = 0;
	min_route[amount_of_visited_nodes] = finish;
	int weight = min_distances[finish];
	while (finish != start)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (communications[i][finish] > 0 && (weight - communications[i][finish] == min_distances[i]))
			{
				weight = weight - communications[i][finish];
				finish = i;
				min_route[++amount_of_visited_nodes] = i;
			}
		}
	}
	min_route[SIZE] = amount_of_visited_nodes;
	return min_route;
}

void Graph::print_min_route(int start, int finish)
{
	int* min_route = find_min_route_deikstra(start, finish);
	for (int i = min_route[SIZE]; i > -1; i--)
	{
		std::cout << min_route[i] << ' ';
	}
	delete[] min_route;
}

int main()
{
	int communications[6][6] = { 0, 4, 4, 6, 6, 0,
								4, 0, 2, 0, 0, 0,
								4, 2, 0, 8, 0, 0,
								6, 0, 8, 0, 9, 1,
								6, 0, 0, 9, 0, 2,
								0, 0, 0, 1, 2, 0 };
	Graph giraffe(communications);
	giraffe.print_min_route(1, 4);
	std::cout << std::endl;
	giraffe.print_min_route(4, 2);
	std::cout << std::endl;
	giraffe.print_min_route(3, 3);
}

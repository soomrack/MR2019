#include <limits.h> 
#include <iostream>
#include <chrono>

constexpr auto number_of_vetrices = 6;

// Функция определяет еще не посещенную вершину u, метка которой минимальна
int minDistance(int distance[], bool vertex_checked[]) {
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < number_of_vetrices; v++)
		if (vertex_checked[v] == false && distance[v] <= min) {
			min = distance[v];
			min_index = v;
		}
	return min_index;
}
 
void printSolution(int distance[], int start_vetrix, int p[]) {

	using namespace std;

	cout<<"Вершина      Расстояние      Путь \n";
	for (int i = 0; i < number_of_vetrices; i++) {
		cout <<"  "<< i << "\t\t" << distance[i] << "\t    ";
		int reverse[number_of_vetrices];
		int counter = 0;
		int temp = p[i];
		cout << start_vetrix;

		while (temp != start_vetrix) {
			reverse[counter] = temp;
			counter++;
			temp = p[temp];
		}
		for (counter; counter > 0; counter--) 
			cout << "->" << reverse[counter-1];

		cout<<"->"<< i << "\n";
	}	
}

void dijkstra(int graph[number_of_vetrices][number_of_vetrices], int start_vetrix)
{
	int distance[number_of_vetrices];
	bool vertex_checked[number_of_vetrices]; 

	for (int i = 0; i < number_of_vetrices; i++) {
		distance[i] = INT_MAX;
		vertex_checked[i] = false;
	}

	distance[start_vetrix] = 0;
	int p[number_of_vetrices];
	p[start_vetrix] = start_vetrix;

	for (int count = 0; count < number_of_vetrices; count++) {

		int current_vertex = minDistance(distance, vertex_checked);
		vertex_checked[current_vertex] = true;

		for (int v = 0; v < number_of_vetrices; v++) 
			if (!vertex_checked[v] && graph[current_vertex][v] && distance[current_vertex] != INT_MAX
				&& distance[current_vertex] + graph[current_vertex][v] < distance[v]) {
				distance[v] = distance[current_vertex] + graph[current_vertex][v]; 
				p[v] = current_vertex;
			}
	}
	printSolution(distance, start_vetrix, p);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int graph[number_of_vetrices][number_of_vetrices] = {{0, 3, 0, 2, 0, 7},
														 {0, 0, 0, 0, 0, 0},
														 {8, 0, 0, 1, 4, 0},
														 {0, 0, 0, 0, 0, 1},
														 {0, 0, 0, 2, 0, 5}, 
														 {0, 0, 0, 0, 1, 0} };

	dijkstra(graph, 2);


	return 0;
}

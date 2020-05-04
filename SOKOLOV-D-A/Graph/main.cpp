#include <iostream>
#include <stdexcept>
#include "Graph.h"
using namespace std;

int main()
{
    Graph graph;
    vector<vector<uint16_t>> adj_matrix = {
//       1 2 3 4 5 6
        {0,7,0,9,0,6},
        {0,0,10,0,0,5},
        {0,0,0,8,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,6},
        {0,0,0,0,0,0}
    };

    graph = Graph(adj_matrix);
    graph.print();
    graph.dijkstra_from(0);

    system("pause");
    return 0;
}


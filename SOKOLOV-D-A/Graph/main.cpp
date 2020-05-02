#include <iostream>
#include <stdexcept>
#include "Graph.h"
using namespace std;

int main()
{
    Graph graph;
    vector<vector<uint16_t>> adj_matrix = {
        {0,7,0,0,0,6},
        {0,0,10,0,0,5},
        {0,0,0,8,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,6},
        {6,0,0,0,0,0}
    };

    //grh.SetSize(4);
    //grh.Input();
    //grh.Output();
    graph = Graph(adj_matrix);
    graph.Output();

    system("pause");
    return 0;
}


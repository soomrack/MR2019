#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <iterator>


Graph::Graph(std::vector<std::vector<uint16_t> > matrix)
    : size(matrix.size())
    , adj_matrix(matrix)
{   
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (adj_matrix[i][j] != 0)
            {
                    nodes.at(i)->add_neighbour(nodes.at(j), adj_matrix[i][j]);    //  добавляем в узел соседей
            }
        }
    }
}


void Graph::SetSize(int size_)
{
    size = size_;
    Resize();
}

void Graph::Output()
{
    for (size_t i = 0; i < size; ++i)
    {
        std::copy(adj_matrix[i].begin(), adj_matrix[i].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (adj_matrix[i][j] != 0)
                std::cout << i + 1 << " node is connected with " << j + 1 << " node [" << adj_matrix[i][j] << "]"<< std::endl;
        }
    }
}

void Graph::Resize()
{
    adj_matrix.resize(size);
    for (size_t i = 0; i < size; ++i)
        adj_matrix[i].resize(size);
}

void Graph::Input()
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (i > j)
                continue;
            std::cout << "Enter 1 for connect " << i + 1 << " node with " << j + 1 << " node: ";
            std::cin >> adj_matrix[i][j];
            if (i != j)
                adj_matrix[j][i] = adj_matrix[i][j];
        }
    }
}



Node::Node(Node* neighbour, size_t weight)
    :is_marked(false)
{
    edge.push_back(std::make_pair(neighbour, weight));
}

void Node::add_neighbour(Node* neighbour, size_t weight)
{
    this->edge.push_back(std::make_pair(neighbour, weight));
}



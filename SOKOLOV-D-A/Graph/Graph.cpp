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
                    nodes.at(j)->add_neighbour(nodes.at(i), adj_matrix[i][j]);
            }
        }
    }
}


void Graph::set_size(int size_)
{
    size = size_;
    resize();
}

void Graph::dijkstra_init(size_t node_number)
{
    for (auto i = nodes.begin(); i != nodes.end(); i++)
    {
        (*i)->path_lenth = SIZE_MAX;
    }
    nodes.at(node_number)->path_lenth = 0;
}

bool Graph::is_there_marked_nodes()
{
    for (auto it = nodes.begin(); it != nodes.end(); it++)
    {
        if (!(*it)->is_marked)
            return false;
    }
    return true;
}

Node* Graph::find_next_node(Node* node)
{
    Node* tmp = new Node();
    tmp->path_lenth = SIZE_MAX;
    for (auto it = node->edge.begin(); it != node->edge.end(); it++)
    {
        if (!it->first->is_marked)
        {
            if (it->first->path_lenth < tmp->path_lenth)
                tmp = it->first;
        }
    }
    if (tmp->is_marked)
        return nullptr;
    return tmp;
}

void Graph::print()
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

void Graph::resize()
{
    adj_matrix.resize(size);
    for (size_t i = 0; i < size; ++i)
        adj_matrix[i].resize(size);
}

void Graph::input_data()
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

void Graph::dijkstra_from(size_t start_node)
{
    dijkstra_init(start_node);

    nodes.at(start_node)->visit_neighbours();
    Node* current_node = nodes.at(start_node);
    while(!is_there_marked_nodes())
    {
        Node* next_node = find_next_node(current_node);
        if (next_node == nullptr)
            break;
        next_node->visit_neighbours();
        current_node = next_node;
    }

}



Node::Node(Node* neighbour, size_t weight)
    :   is_marked(false)
    ,   path_lenth(SIZE_MAX)
{
    edge.push_back(std::make_pair(neighbour, weight));
}

void Node::add_neighbour(Node* neighbour, size_t weight)
{
    this->edge.push_back(std::make_pair(neighbour, weight));
}

void Node::visit_neighbours()
{
    for (auto edge = this->edge.begin(); edge != this->edge.end(); edge++)
    {
        if(edge->first->is_marked == false && edge->first->path_lenth > this->path_lenth + edge->second)
            edge->first->path_lenth = this->path_lenth + edge->second;
    }
    this->is_marked = true;
}



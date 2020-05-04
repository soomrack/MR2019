#pragma once
#include <vector>
#include <array>
#include <list>

class Node
{
    using pair = std::pair<Node*, size_t>;
public:
    Node() = default;
    Node(Node* neighbour, size_t weight);
    ~Node() = default;

    void add_neighbour(Node* neighbour, size_t weight);
    void visit_neighbours();

    bool is_marked;
    std::list<pair> edge;
    size_t path_lenth;
};

class Graph
{
public:
    Graph() = default;
    Graph(std::vector<std::vector<uint16_t> > matrix);
    ~Graph() = default;

    
    inline const int get_size() const { return size; }
    inline Node* const get_node(size_t number) const { return nodes.at(number); };
    void print();   
    void input_data();

    void dijkstra_from(size_t start_node);

private:
    void resize();
    void set_size(int size_);
    // dijkstra

    void dijkstra_init(size_t node_number);
    bool is_there_marked_nodes();
    Node* find_next_node(Node* node);
    

    size_t size;
    std::vector<std::vector<uint16_t> > adj_matrix;
    std::array<Node*, 6> nodes = { {new Node(), new Node(), new Node(), new Node(), new Node(), new Node()} };
    
};


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

private:
    bool is_marked;
    std::list<pair> edge;
};

class Graph
{
public:
    Graph() = default;
    Graph(std::vector<std::vector<uint16_t> > matrix);
    ~Graph() = default;

    void SetSize(int size_);
    inline const int GetSize() const { return size; }
    void Output();
    void Resize();
    void Input();
private:
    size_t size;
    std::vector<std::vector<uint16_t> > adj_matrix;
    std::array<Node*, 6> nodes = { {new Node(), new Node(), new Node(), new Node(), new Node(), new Node()} };
    
};


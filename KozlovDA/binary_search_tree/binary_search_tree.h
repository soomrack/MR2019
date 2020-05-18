#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Node
{
public:
	int key;
	void* data;
	Node* left_child;
	Node* right_child;
public:
	Node(int key, void* data);
	~Node();
	void print_key();
};

class Tree
{
public:
	Node* root;
private:
	Node* search_parent_for_new_data(int key, Node* root);
	Node* search_parent(int key, Node* root);
	Node* find_max_node(Node* root);
	Node* next_node(bool restart = false);
	void delete_node_with_2_children(Node* redundant_node);
	void delete_node_with_left_child(Node* redundant_node);
	void delete_node_with_right_child(Node* redundant_node);
	void delete_node_without_children(Node* redundant_node);
public:
	Tree() 
	{ 
		root = nullptr; 
	}
	~Tree() {};
	void delete_tree(Node* root);
	void add_data(int key, void* data);
	Node* search(int key);
	void delete_node(int key);
	void print_with_levels_and_directions(Node* root, const char* dir, int level);
	void print_in_direct_order(Node* root);
	void print();
};

#endif
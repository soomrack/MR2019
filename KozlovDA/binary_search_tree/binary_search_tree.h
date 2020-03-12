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
};

class Tree
{
public:
	Node* root;
private:
	Node* search_parent_for_new_data(int key, Node* root);
	Node* search_parent(int key, Node* root);
	Node* find_max_node(Node* root);
	void copy_key_and_data(Node* CopyIn, Node* CopyFrom);
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
	void print_tree_with_levels_and_directions(Node* root, const char* dir, int level);
	void print_tree_in_direct_order(Node* root);
};

#endif
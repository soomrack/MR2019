#ifndef TREEMETHODS_H
#define TREEMETHODS_H

#define T 3  //степень дерева

class Node
{
public:
	Node* parent;
	int elements[3];	//как то поправить 3 на t
	Node* child[4];
	Node();
	const int t = T; //степень дерева
};

class Tree
{
public:
	const int t = T; //степень дерева
	Node* root ;
	Tree();
public:
	void add_element(int key);
	void delete_element();
	Node* search_node(Node* root, int key);
	void print_tree(Node* root);
private:
	Node* search_leaf_for_new_key(Node* root, int key);
	void insert_key(Node* node, int key, Node* add_child);
	void shift_elements_and_children(Node* node, int start);
	int count_children_amount(Node* node);
	int count_key_amount(Node* node);
	void split(Node* node);
	void delete_data_left_node(Node* node);
	void copy_data_to_right_node(Node* node, Node* new_node_right);
	void copy_data_to_top_node(Node* node, Node* new_node_top, Node* new_node_right);
};
#endif 


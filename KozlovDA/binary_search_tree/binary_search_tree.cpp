#include "binary_search_tree.h"
#include <iostream>

Node::Node (int key, void* data)
{
	this->key = key;
	this->data = data;
	left_child = nullptr;
	right_child = nullptr;
}

Node::~Node()
{
	delete left_child;
	delete right_child;
}

Node* Tree::search_parent_for_new_data(int key, Node* root)
{
	if (root == nullptr)
		return nullptr;
	Node* next_child = nullptr;
	if (key < (root->key))
	{
		if (root->left_child)
			next_child = root->left_child;
		else
			return root;
	}
	else
	{	
		if (root->right_child)
			next_child = root->right_child;
		else
			return root;
	}
	return search_parent_for_new_data(key, next_child);
}

Node* Tree::search_parent(int key, Node* root)
{
	if (root == nullptr)
		return nullptr;
	Node* next_child = nullptr;
	if (key < root->key && root->left_child)
	{
		if (root->left_child->key == key)
			return root;
		else
			next_child = root->left_child;
	}
	if (key >= root->key && root->right_child)
	{
		if (root->right_child->key == key)
			return root;
		else
			next_child = root->right_child;
	}
	return search_parent(key, next_child);
}

Node* Tree::find_max_node(Node* node)
{
	while (node->right_child)
		node = node->right_child;
	return node;
}

void Tree::add_data(int key, void* data)
{
	Node* new_node = new Node(key, data);
	Node* parent_of_new_node = search_parent_for_new_data(key, root);
	if (!parent_of_new_node)
	{
		root = new_node;
		return;
	}
	if (parent_of_new_node)
	{
		if (key < parent_of_new_node->key)
		{
			parent_of_new_node->left_child = new_node;
		}
		else
		{
			parent_of_new_node->right_child = new_node;
		}
	}
}

Node* Tree::search(int key)
{
	Node* current_node = root;
	while (current_node && current_node->key != key)
	{
		if (key < current_node->key)
		{
			current_node = current_node->left_child;
		}
		else
		{
			current_node = current_node->right_child;
		}
	}
	return current_node;
}

void Tree::delete_node_with_2_children(Node* redundant_node)
{
	Node* parent_of_redundant_node = search_parent(redundant_node->key, root);
	Node* successor = find_max_node(redundant_node->left_child);
	Node* parent_of_successor = search_parent(successor->key, root);
	if (parent_of_redundant_node->left_child == redundant_node)
		parent_of_redundant_node->left_child = successor;
	if (parent_of_redundant_node->right_child == redundant_node)
		parent_of_redundant_node->right_child = successor;
	if (redundant_node == parent_of_successor)
	{
		successor->right_child = redundant_node->right_child;
	}
	if (redundant_node != parent_of_successor)
	{
		parent_of_successor->right_child = successor->left_child;
		successor->right_child = redundant_node->right_child;
		successor->left_child = redundant_node->left_child;
	}
	redundant_node->left_child = nullptr;
	redundant_node->right_child = nullptr;
	delete redundant_node;
}

void Tree::delete_node_with_left_child(Node* redundant_node)
{
	Node* parent_of_redundant_node = search_parent(redundant_node->key, root);
	if (redundant_node == parent_of_redundant_node->left_child)
		parent_of_redundant_node->left_child = redundant_node->left_child;
	if (redundant_node == parent_of_redundant_node->right_child)
		parent_of_redundant_node->right_child = redundant_node->left_child;
	redundant_node->left_child = nullptr;
	delete redundant_node;
}

void Tree::delete_node_with_right_child(Node* redundant_node)
{
	Node* parent_of_redundant_node = search_parent(redundant_node->key, root);
	if (redundant_node == parent_of_redundant_node->left_child)
		parent_of_redundant_node->left_child = redundant_node->right_child;
	if (redundant_node == parent_of_redundant_node->right_child)
		parent_of_redundant_node->right_child = redundant_node->right_child;
	redundant_node->right_child = nullptr;
	delete redundant_node;
}

void Tree::delete_node_without_children(Node* redundant_node)
{
	Node* parent_of_redundant_node = search_parent(redundant_node->key, root);
	if (redundant_node == parent_of_redundant_node->left_child)
		parent_of_redundant_node->left_child = nullptr;
	if (redundant_node == parent_of_redundant_node->right_child)
		parent_of_redundant_node->right_child = nullptr;
	delete redundant_node;
}

void Tree::delete_node(int key) //�������� �� ������� �� ������ private �������� ��� ������� ������
{								// ������� ��� ����������� ����������: ���������, redundant_node, ...
	Node* redundant_node = search(key);
	if (redundant_node == nullptr)
		return;
	if (redundant_node->left_child && redundant_node->right_child)
	{
		delete_node_with_2_children(redundant_node);
		return;
	}
	if (redundant_node->left_child && !redundant_node->right_child)
	{
		delete_node_with_left_child(redundant_node);
		return;
	}
	if (!redundant_node->left_child && redundant_node->right_child)
	{
		delete_node_with_right_child(redundant_node);
		return;
	}
	if (!redundant_node->left_child && !redundant_node->right_child)	
		delete_node_without_children(redundant_node);
}

void Tree::print_tree_with_levels_and_directions(Node* root, const char* dir, int level) {
	if (root) 
	{
		std::cout << "lvl " << level << " " << dir << " = " << root->key << std::endl;
		print_tree_with_levels_and_directions(root->left_child, "left", level + 1);
		print_tree_with_levels_and_directions(root->right_child, "right", level + 1);
	}
}

void Tree::print_tree_in_direct_order(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->key << std::endl;
		print_tree_in_direct_order(root->left_child);
		print_tree_in_direct_order(root->right_child);
	}
	else
		return;
}

void Tree::delete_tree(Node* root)
{
	delete root;
	if (root == this->root)
	{
		this->root = nullptr;
	}
	else
	{
		Node* parent = search_parent(root->key, this->root);
		if (parent->left_child == root)
			parent->left_child = nullptr;
		if (parent->right_child == root)
			parent->right_child = nullptr;
	}
}
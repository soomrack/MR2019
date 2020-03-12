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
	Node* child = nullptr;
	if (root != nullptr)
	{
		if (key < (root->key))
		{
			if (root->left_child)
				child = root->left_child;
			else
				return root;
		}
		else
		{	
			if (root->right_child)
				child = root->right_child;
			else
				return root;
		}
		return search_parent_for_new_data(key, child);
	}
	else
	{
		return nullptr;
	}
}

Node* Tree::search_parent(int key, Node* root)
{
	if (root != nullptr)
	{
		if (key < root->key)
		{
			if (root->left_child && root->left_child->key == key)
				return root;
			else
				return search_parent(key, root->left_child);
		}
		else
		{
			if (root->right_child && root->right_child->key == key)
				return root;
			else
				return search_parent(key, root->right_child);
		}
	}
	else
		return nullptr;
}

void Tree::copy_key_and_data(Node* copy_in, Node* CopyFrom)
{
	copy_in->key = CopyFrom->key;
	copy_in->data = CopyFrom->data;
}

Node* Tree::find_max_node(Node* root)
{
	while (root->right_child)
		root = root->right_child;
	return root;
}

void Tree::add_data(int key, void* data)
{
	Node* new_node = new Node(key, data);
	Node* parent = search_parent_for_new_data(key, root);
	if (parent != nullptr)
	{
		if (key < parent->key)
		{
			parent->left_child = new_node;
		}
		else
		{
			parent->right_child = new_node;
		}
	}
	else
	{
		root = new_node;
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

void Tree::delete_node(int key)
{
	Node* parent = search_parent(key, root);
	Node* node_to_delete = search(key);
	if (node_to_delete == nullptr)
		return;
	else if (node_to_delete->left_child && node_to_delete->right_child)
	{
		Node* max_node = find_max_node(node_to_delete->left_child);
		Node* parent_of_max_node = search_parent(max_node->key, root);
		copy_key_and_data(node_to_delete, max_node);
		if (max_node == parent_of_max_node->left_child)
			parent_of_max_node->left_child = max_node->left_child;
		else
			parent_of_max_node->right_child = max_node->left_child;
		delete max_node;
	}
	else if (node_to_delete->left_child && !node_to_delete->right_child)
	{
		if (node_to_delete == parent->left_child)
			parent->left_child = node_to_delete->left_child;
		else
			parent->right_child = node_to_delete->left_child;
		delete node_to_delete; 
	}
	else if (node_to_delete->right_child && !node_to_delete->left_child)
	{
		if (node_to_delete == parent->left_child)
			parent->left_child = node_to_delete->right_child;
		else
			parent->right_child = node_to_delete->right_child;
		delete node_to_delete;
	}
	else
	{
		if (node_to_delete == parent->left_child)
			parent->left_child = nullptr;
		else
			parent->right_child = nullptr;
		delete node_to_delete;
	}
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
		this->root = nullptr;
	else
	{
		Node* parent = search_parent(root->key, this->root);
		if (root == parent->left_child)
			parent->left_child = nullptr;
		else
			parent->right_child = nullptr;
	}
}
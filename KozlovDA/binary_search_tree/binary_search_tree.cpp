#include "binary_search_tree.h"
#include <iostream>

Node::Node (int key, void* data)
{
	this->key = key;
	this->data = data;
	left_child = nullptr;
	right_child = nullptr;
}

Node* Tree::search_parent_for_new_data(int key, Node* root)
{
	Node* child = nullptr;
	if (root != nullptr)
	{
		if (key < (root->key))
		{
			if (root->left_child != nullptr)
				child = root->left_child;
			else
				return root;
		}
		else
		{	
			if (root->right_child != nullptr)
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
			if (root->left_child->key == key)
				return root;
			else
				return search_parent(key, root->left_child);
		}
		else
		{
			if (root->right_child->key == key)
				return root;
			else
				return search_parent(key, root->right_child);
		}
	}
	else
		return nullptr;
}

void Tree::copy_key_and_data(Node* CopyIn, Node* CopyFrom)
{
	CopyIn->key = CopyFrom->key;
	CopyIn->data = CopyFrom->data;
}

Node* Tree::find_max_node(Node* root)
{
	if (root->right_child)
		root = find_max_node(root->right_child);
	return root;
}

void Tree::add_data(int key, void* data)
{
	Node* NewNode = new Node(key, data);
	Node* parent = search_parent_for_new_data(key, root);
	if (parent != nullptr)
	{
		if (key < parent->key)
		{
			parent->left_child = NewNode;
		}
		else
		{
			parent->right_child = NewNode;
		}
	}
	else
	{
		root = NewNode;
	}
}

Node* Tree::search(int key)
{
	Node* CurrentNode = root;
	while (CurrentNode->key != key && CurrentNode != nullptr)
	{
		if (key < CurrentNode->key)
		{
			CurrentNode = CurrentNode->left_child;
		}
		else
		{
			CurrentNode = CurrentNode->right_child;
		}
	}
	return CurrentNode;
}

void Tree::delete_node(int key)
{
	Node* Parent = search_parent(key, root);
	Node* NodeToDelete = search(key);
	if (NodeToDelete->left_child && NodeToDelete->right_child)
	{
		Node* MaxNode = find_max_node(NodeToDelete->left_child);
		Node* ParentOfMaxNode = search_parent(MaxNode->key, root);
		copy_key_and_data(NodeToDelete, MaxNode);
		if (MaxNode == ParentOfMaxNode->left_child)
			ParentOfMaxNode->left_child = nullptr;
		else
			ParentOfMaxNode->right_child = nullptr;
		delete MaxNode;
	}
	else if (NodeToDelete->left_child && !NodeToDelete->right_child)
	{
		if (NodeToDelete == Parent->left_child)
			Parent->left_child = NodeToDelete->left_child;
		else
			Parent->right_child = NodeToDelete->left_child;
		delete NodeToDelete;
	}
	else if (NodeToDelete->right_child && !NodeToDelete->left_child)
	{
		if (NodeToDelete == Parent->left_child)
			Parent->left_child = NodeToDelete->right_child;
		else
			Parent->right_child = NodeToDelete->right_child;
		delete NodeToDelete;
	}
	else
	{
		if (NodeToDelete == Parent->left_child)
			Parent->left_child = nullptr;
		else
			Parent->right_child = nullptr;
		delete NodeToDelete;
	}
}

void Tree::print_tree(Node* root, const char* dir, int level) {
	if (root) 
	{
		std::cout << "lvl " << level << " " << dir << " = " << root->key << std::endl;
		print_tree(root->left_child, "left", level + 1);
		print_tree(root->right_child, "right", level + 1);
	}
}
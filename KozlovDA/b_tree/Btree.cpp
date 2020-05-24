#include "Btree.h"
#include <queue>
#include <iostream>

BNode::BNode()
{
	for (int i = 0; i < (2 * t - 1); i++)
		keys[i] = 0;
	for (int i = 0; i < (2 * t); i++)
		children[i] = nullptr;
	count = 0;
	leaf = false;
}

void BNode::print()
{
	std::cout << "Node: " << this << std::endl;
	std::cout << "keys: ";
	for (int i = 0; i < (2 * t - 1); i++)
		std::cout << keys[i] << " ";
	std::cout << std::endl;
	std::cout << "children: ";
	for (int i = 0; i < (2 * t); i++)
		std::cout << children[i] << " ";
	std::cout << std::endl;
}

void Tree::sort_node(BNode* node)
{
	int borderOfSortedArray = node->count;
	int posSortedElem = borderOfSortedArray - 1;
	int unsortedElem = node->keys[borderOfSortedArray];
	while (posSortedElem >= 0 && unsortedElem < node->keys[posSortedElem])
	{
		node->keys[posSortedElem + 1] = node->keys[posSortedElem];
		posSortedElem--;
	}
	node->keys[posSortedElem + 1] = unsortedElem;
}

BNode* Tree::search_parent(BNode* node, BNode* root)
{
	for (int i = 0; i < (2 * t); i++)
	{
		if (root->children[i] == node) return root;
	}
	for (int i = 0; i < (2 * t); i++)
	{
		if (root->children[i]) search_parent(node, root->children[i]);
	}
}

void Tree::insert_to_node(int key, BNode* node)
{
	node->keys[node->count] = key;
	sort_node(node);
	node->count++;
}

BNode* Tree::find_position_for_new_node(int key)
{
	BNode* current_node = root;
	while (!current_node->leaf)
	{
		for (int i = 0; i < (2 * t - 1); i++)
		{
			if (key <= current_node->keys[i])
			{
				current_node = current_node->children[i];
				break;
			}
			if ((current_node->keys[i + 1] == 0) && (key > current_node->keys[i]))
			{
				current_node = current_node->children[i + 1];
				break;
			}
		}
	}
	return current_node;
}

int Tree::binary_search(int* a, int first, int last, const int x)
{
	if (first == last) return(first);
	int middle = (last - first + 1) / 2 + first;
	if (a[middle] <= x) return (binary_search(a, middle, last, x));
	else return (binary_search(a, first, middle - 1, x));
}

BNode* Tree::find_node(int key, BNode* root)
{
	int suspected = binary_search(root->keys, 0, root->count - 1, key);
	if (key == root->keys[suspected]) return root;
	else if (key <= root->keys[suspected]) return find_node(key, root->children[suspected]);
	else return find_node(key, root->children[suspected + 1]);
}

void Tree::add_data(int key)
{
	if (!root)
	{
		BNode* new_node = new BNode;
		new_node->keys[0] = key;
		new_node->count++;
		new_node->leaf = true;
		root = new_node;
	}
	else
	{
		BNode* node = find_position_for_new_node(key);
		insert_to_node(key, node);
		while (node->count == (2 * t - 1))
		{
			if (node == root)
			{
				restruct(node);
				break;
			}
			else
			{
				BNode* parent = search_parent(node, this->root);
				restruct(node);
				node = parent;
			}
		}
	}
}

void Tree::delete_node(int key) //удаляет лист
{
	BNode* redundant_node = find_node(key, root);
	BNode* parent_of_redundant_node = search_parent(redundant_node, root);
	if (!redundant_node->leaf) return;
	for (int i = 0; i < (2 * t); i++)
	{
		if (parent_of_redundant_node->children[i] == redundant_node)
			parent_of_redundant_node->children[i] = nullptr;
	}
	delete redundant_node;
}

void Tree::delete_tree(BNode* root)
{
	for (int i = 0; i < (2 * t); i++)
	{
		if (root->children[i])
		{
			if (root->children[i]->leaf) delete_node(root->children[i]->keys[0]);
			else delete_tree(root->children[i]);
		}
	}
	delete root;
	this->root = nullptr;
}

void Tree::restruct(BNode* node)
{
	BNode* child1 = new BNode;
	for (int j = 0; j < (t - 1); j++)
	{
		child1->keys[j] = node->keys[j];
		child1->count++;
	}
	if (!node->leaf)
	{
		for (int j = 0; j < t; j++)
		{
			child1->children[j] = node->children[j];
		}
	}
	BNode* child2 = new BNode;
	for (int j = 0; j < (t - 1); j++)
	{
		child2->keys[j] = node->keys[j + t];
		child2->count++;
	}
	if (!node->leaf)
	{
		for (int j = 0; j < t; j++)
		{
			child2->children[j] = node->children[j+ t];
		}
	}
	if (node->leaf)
	{
		child1->leaf = true;
		child2->leaf = true;
	}
	if (node == root)
	{
		node->keys[0] = node->keys[t - 1];
		for (int j = 1; j < (2 * t - 1); j++) node->keys[j] = 0;
		node->children[0] = child1;
		node->children[1] = child2;
		for (int j = 2; j < (2 * t); j++) node->children[j] = nullptr;
		node->leaf = false;
		node->count = 1;
	}
	else
	{
		BNode* parent = search_parent(node, this->root);
		insert_to_node(node->keys[t - 1], parent);
		for (int j = 0; j < (2 * t); j++)
		{
			if (parent->children[j] == node) parent->children[j] = nullptr;
		}
		for (int i = 0; i < (2 * t); i++) 
		{
			if (parent->children[i] == nullptr) 
			{
				for (int j = (2 * t - 1); j > (i + 1); j--) 
					parent->children[j] = parent->children[j - 1];
				parent->children[i] = child1;
				parent->children[i + 1] = child2;
				break;
			}
		}
	}
}

BNode* Tree::next_node_bsf(const bool restart = false)
{
	static std::queue <BNode*> check_children;
	if (check_children.empty() && !restart) return nullptr;
	if (restart)
	{
		while (!check_children.empty())
			check_children.pop();
		check_children.push(root);
	}
	BNode* current_node = check_children.front();
	check_children.pop();
	if (!current_node->leaf)
	{
		for (int i = 0; i < (2 * t); i++)
		{
			if (current_node->children[i])
				check_children.push(current_node->children[i]);
		}
	}
	return current_node;
}

void Tree::print()
{
	if (!root) return;
	next_node_bsf(true)->print();
	std::cout << std::endl;
	while (BNode* node = next_node_bsf())
	{
		node->print();
		std::cout << std::endl;
	}
}

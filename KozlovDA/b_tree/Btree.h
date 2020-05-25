#ifndef BTREE_H
#define BTREE_H

const int t = 4;

class BNode
{
public:
	int keys[2 * t - 1];
	BNode* children[2 * t];
	int count;
	bool leaf;
public:
	BNode();
	~BNode() {};
	void print();
};

class Tree
{
public:
	BNode* root;
public:
	Tree() { root = nullptr; };
	~Tree() {};
	BNode* find_node(int key, BNode* root);
	void add_data(int key);
	void delete_tree(BNode* root);
	void delete_node(int key);
	void print();
private:
	int binary_search(int* a, int first, int last, const int x);
	BNode* search_parent(BNode* node, BNode* root);
	void insert_to_node(int key, BNode* node);
	void sort_node(BNode* node);
	BNode* find_position_for_new_node(int key);
	void restruct(BNode* node);
	BNode* next_node_bsf(const bool restart);
};

#endif

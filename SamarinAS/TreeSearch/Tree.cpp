#include <iostream>
using namespace std;

class Node
{
	public:
		int key;
		void* data;
		Node* left_cha;
		Node* right_cha;

	public:
		Node(int key, void* data);

		~Node() {};
};

Node::Node(const int key, void* data)  //
{
	this->key = key;
	this->data = data;
	left_cha = nullptr;
	right_cha = nullptr;

}


class Tree
{
public:
	Node * root;

public:
	Tree() 
	{
		root = nullptr;
	}
	~Tree() {};

private:
	Node* search_parent_for_new_node(int key, Node * root);
public:
	int add_data(int key, void* data); 

};

Node* Tree::search_parent_for_new_node(int key, Node * root) {
	if (root->key <= key) {
		if (root->left_cha == nullptr) return root;
		return search_parent_for_new_node(key, root->left_cha);
	}
	if (root->right_cha == nullptr) return root;
	return search_parent_for_new_node(key, root->right_cha);
}

int Tree::add_data(int key, void* data)
{
	Node* child = new Node(key, data);

	if (root == nullptr) {
		root = child;
		return 1;
	}

	Node* parent = search_parent_for_new_node(key, root);

	if (key <= parent->key) {
		parent->left_cha = child;
	}
	else {
		parent->right_cha = child;
	}
	return 1;
}


int main()
{
	int b = 5;
	Tree mytree = Tree();

	mytree.add_data(5, nullptr);
	mytree.add_data(1, nullptr);
	mytree.add_data(3, nullptr);
	mytree.add_data(9, nullptr);
	mytree.add_data(5, nullptr);
	mytree.add_data(8, nullptr);
	mytree.add_data(4, nullptr);


}

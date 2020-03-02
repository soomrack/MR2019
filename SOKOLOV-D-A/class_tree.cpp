#include <iostream>


class Node
{
public:
	int key;
	void* data;
	Node* left;
	Node* right;
	Node()
		: key(0)
		, data(nullptr)
		, left(nullptr)
		, right(nullptr) {}

	Node(void* data, int key)
		: key(key)
		, data(new void* (data))
		, left(new Node())
		, right(new Node())
	{}
	Node(const Node& other)
		: key(other.key)
		, data(new void* (other.data))
		, left(other.left)
		, right(other.right)
	{}

	~Node() { }

};



class Tree : public Node
{
	Node* root;

	Node* add_data(void* data, const int key, Node* root)
	{

		if (root->key == 0)
		{
			Node* child = new Node(data, key);
			root = child;
			return root;
		}

		if (key <= root->key)
		{
			root->left = add_data(data, key, root->left);
		}

		else if (key > root->key)
		{
			root->right = add_data(data, key, root->right);
		}
		return root;

	}
public:
	Tree()
	{
		this->root = nullptr;
	}

	~Tree() {}


	Node* search(Node* root, int key)
	{
		if (root == nullptr || root->key == key)
			return root;

		if (root->key <= key)
			return search(root->right, key);

		return search(root->left, key);
	}


	int add_data(void* data, const int key)
	{
		if (this->root == nullptr)
		{
			Node* child = new Node(data, key);
			this->root = child;
			return 0;
		}
		if (key <= this->root->key)
		{
			this->root->left = add_data(data, key, this->root->left);
		}

		else if (key > this->root->key)
		{
			this->root->right = add_data(data, key, this->root->right);
		}
		return 0;
	}


	void delete_data(const int key)
	{
		delete search(this->root, key);
	}
};





int main()
{
	//bin tree
	int a = 5;
	int b = 5 * 5;
	int c = 6;
	int d = 9;
	Tree tree;
	tree.add_data(&a, 5);
	tree.add_data(&b, 25);
	tree.add_data(&c, 4);
	tree.add_data(&d, 50);
	tree.delete_data(4);

	system("pause");

	return 0;
}



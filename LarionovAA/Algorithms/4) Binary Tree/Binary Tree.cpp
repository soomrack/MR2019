#include <iostream>

class Node
{
public:
	int key;
	void* data;
	Node* leftNode;
	Node* rightNode;
public:
	Node(const int key, void* data);
	~Node() {};
};

Node::Node(const int key, void* data)
{
	this->key = key;
	this->data = data;
	leftNode = nullptr;
	rightNode = nullptr;
}


class Tree
{
private:
	int index = 0; // For output_array()
public:
	Node* root;
public:
	Tree()
	{
		root = nullptr;
	}
	~Tree() {};
private:
	Node* minimum(Node* root); // original
	Node* search_parent_for_adding(const int key, Node* root);
	void output_array(int* array, Node* root);
public:
	Node* delete_node(int key, Node* root); // original
	void output(Node* root); // original
	int add_node(const int key, void* data);
	void print_binary_tree(int* array, int size);
};


Node* Tree::minimum(Node* root) // original
{
	if (root->leftNode == nullptr)
	{
		return root;
	}

	return minimum(root->leftNode);
}

Node* Tree::search_parent_for_adding(const int key, Node* root)
{
	if (root->key != key)
	{
		if (key < root->key)
		{
			if (root->leftNode == nullptr)
			{
				return root;
			}
			return search_parent_for_adding(key, root->leftNode);
		}
		else if (key > root->key)
		{
			if (root->rightNode == nullptr)
			{
				return root;
			}
			return search_parent_for_adding(key, root->rightNode);
		}
	}

	return root;
}

void Tree::output_array(int* array, Node* root) 
{
	if (root != nullptr)
	{
		array[index] = root->key;
		index++;
		output_array(array, root->leftNode);
		output_array(array, root->rightNode);
	}

	return;
}


Node* Tree::delete_node(int key, Node* root) // original
{
	if (root == nullptr)
	{
		return root;
	}
	if (key < root->key)
	{
		root->leftNode = delete_node(key, root->leftNode);
	}
	else if (key > root->key)
	{
		root->rightNode = delete_node(key, root->rightNode);
	}
	else if ((root->leftNode != nullptr) && (root->rightNode != nullptr))
	{
		root->key = minimum(root->rightNode)->key;
		root->data = minimum(root->rightNode)->data;
		root->rightNode = delete_node(root->key, root->rightNode);
	}
	else if (root->leftNode != nullptr)
	{
		root = root->leftNode;
	}
	else if (root->rightNode != nullptr)
	{
		root = root->rightNode;
	}
	else
	{
		root = nullptr;
	}

	return root;
}

void Tree::output(Node* root) // original (another name - preorderTraversal)
{
	if (root != nullptr)
	{
		std::cout << root->key;
		std::cout << " ";
		output(root->leftNode);
		output(root->rightNode);
	}

	return;
}

int Tree::add_node(const int key, void* data)
{
	Node* child = new Node(key, data);

	if (root == nullptr)
	{
		root = child;

		return 1;
	}

	Node* parent = search_parent_for_adding(key, root);

	if (parent->key == key)
	{
		parent->key = key;
		parent->data = data;
	}
	else if (key < parent->key)
	{
		parent->leftNode = child;
	}
	else if (key > parent->key)
	{
		parent->rightNode = child;
	}

	return 1;
}

void print_binary_heap(const int* array, const int size) // Previously completed function
{
	for (int i = 0; ; i++)
	{
		std::cout << std::endl;
		int levelIndex = (int)pow(2, i) - 1; // First level element 
		int k = 0;
		do
		{
			if (levelIndex >= size)
			{
				std::cout << std::endl;
				return;
			}
			std::cout << array[levelIndex] << " ";
			levelIndex++;
			k++;
		} while (k < (int)pow(2, i));
	}
}

void Tree::print_binary_tree(int* array, int size)
{
	output_array(array, root);
	index = 0;

	int buffer[127] = { 0 }; // 127 = sum(2^k), where k = 0...6
	int sizeOfBuffer = 127;

	int k = 0;
	buffer[k] = array[k];

	while ((k + 1) < size)
	{
		for (int i = 0; ; )
		{
			if ((array[k + 1] < buffer[i]) && (buffer[2 * i + 1] != 0))
			{
				i = 2 * i + 1;
			}
			else if ((array[k + 1] < buffer[i]) && (buffer[2 * i + 1] == 0))
			{
				buffer[2 * i + 1] = array[k + 1];
				break;
			}
			else if ((array[k + 1] > buffer[i]) && (buffer[2 * i + 2] != 0))
			{
				i = 2 * i + 2;
			}
			else if ((array[k + 1] > buffer[i]) && (buffer[2 * i + 2] == 0))
			{
				buffer[2 * i + 2] = array[k + 1];
				break;
			}
		}
		k++;
	}

	print_binary_heap(buffer, sizeOfBuffer);

	return;
}


int main()
{
	Tree binaryTree;

	binaryTree.add_node(8, nullptr);
	binaryTree.add_node(1, nullptr);
	binaryTree.add_node(6, nullptr);
	binaryTree.add_node(3, nullptr);
	binaryTree.add_node(11, nullptr);
	binaryTree.add_node(-7, nullptr);
	binaryTree.add_node(4, nullptr);
	binaryTree.add_node(5, nullptr);
	binaryTree.output(binaryTree.root);

	//First test (Re-adding)
	binaryTree.add_node(6, nullptr);
	std::cout << std::endl;
	binaryTree.output(binaryTree.root);

	//Second test (Adding)
	binaryTree.add_node(-1, nullptr);
	std::cout << std::endl;
	binaryTree.output(binaryTree.root);
	
	//Array length is equal to number of unique nodes!
	//Function is not perfect but useful
	int outputOne[9] = { 0 };
	int sizeOne = 9;
	std::cout << std::endl;
	binaryTree.print_binary_tree(outputOne, sizeOne);

	//Third test (Destruction)
	binaryTree.delete_node(1, binaryTree.root); 
	std::cout << std::endl;
	binaryTree.output(binaryTree.root);

	//
	int outputTwo[8] = { 0 };
	int sizeTwo = 8;
	std::cout << std::endl;
	binaryTree.print_binary_tree(outputTwo, sizeTwo);

	return 0;
}
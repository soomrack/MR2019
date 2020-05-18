#include <iostream>
#include <queue>
#include <stack>

static int countNode = 0;


class Node
{
public:
	int key;
	void* data;
	Node* leftNode;
	Node* rightNode;
public:
	Node(const int key, void* data);
	~Node();
};

Node::Node(const int key, void* data)
{
	this->key = key;
	this->data = data;
	leftNode = nullptr;
	rightNode = nullptr;
	countNode++;
}

Node::~Node()
{
	delete leftNode;
	delete rightNode;
	countNode--;
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
	Node* search_node_for_deleting(int key, Node* root);
	Node* search_parent_for_deleting(int key, Node* root);
	void output_array(int* array, Node* root);
	Node* next_node_width(const bool restart);
	Node* next_node_length(const bool restart);
	Node* next_node_sort(const bool restart);
public:
	Node* delete_node(int key, Node* root); // original
	void output(Node* root); // original
	int add_node(const int key, void* data);
	int delete_one_node(int key);
	void print_binary_tree(int* array, int size);
	void print_certain_order();
	void delete_binary_tree();
};

//"While" is better
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

Node* Tree::search_node_for_deleting(int key, Node* root)
{
	if (root != nullptr)
	{
		if (root->key == key)
		{
			return root;
		}
		if (key < root->key)
		{
			return search_node_for_deleting(key, root->leftNode);
		}
		else if (key > root->key)
		{
			return search_node_for_deleting(key, root->rightNode);
		}
	}

	return root;
}

Node* Tree::search_parent_for_deleting(int key, Node* root)
{
	if (root != nullptr)
	{
		if (key < root->key)
		{
			if ((root->leftNode != nullptr) && ((root->leftNode)->key == key))
			{
				return root;
			}
			return search_parent_for_deleting(key, root->leftNode);
		}
		else if (key > root->key)
		{
			if ((root->rightNode != nullptr) && ((root->rightNode)->key == key))
			{
				return root;
			}
			return search_parent_for_deleting(key, root->rightNode);
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

Node* Tree::next_node_width(const bool restart)
{
	static std::queue <Node*> checkNextNode;

	if (restart == 1)
	{
		while (checkNextNode.empty() != true)
		{
			checkNextNode.pop();
		}
		checkNextNode.push(root);
	}

	if (checkNextNode.empty() == true)
	{
		return nullptr;
	}

	Node* currentNode = checkNextNode.front();
	checkNextNode.pop();

	if ((currentNode != nullptr) && (currentNode->leftNode != nullptr))
	{
		checkNextNode.push(currentNode->leftNode);
	}
	if ((currentNode != nullptr) && (currentNode->rightNode != nullptr))
	{
		checkNextNode.push(currentNode->rightNode);
	}

	return currentNode;
}

Node* Tree::next_node_length(const bool restart)
{
	static std::stack <Node*> checkNextNode;

	if (restart == 1)
	{
		while (checkNextNode.empty() != true)
		{
			checkNextNode.pop();
		}
		checkNextNode.push(root);
	}

	if (checkNextNode.empty() == true)
	{
		return nullptr;
	}

	Node* currentNode = checkNextNode.top();
	checkNextNode.pop();

	if ((currentNode != nullptr) && (currentNode->rightNode != nullptr))
	{
		checkNextNode.push(currentNode->rightNode);
	}
	if ((currentNode != nullptr) && (currentNode->leftNode != nullptr))
	{
		checkNextNode.push(currentNode->leftNode);
	}

	return currentNode;
}

Node* Tree::next_node_sort(const bool restart)
{
	static std::stack <Node*> checkNextNode;

	if (restart == 1)
	{
		while (checkNextNode.empty() != true)
		{
			checkNextNode.pop();
		}

		Node* initialNode = root;
		while (initialNode != nullptr)
		{
			checkNextNode.push(initialNode);
			initialNode = initialNode->leftNode;
		}
	}

	if (checkNextNode.empty() == true)
	{
		return nullptr;
	}

	Node* currentNode = checkNextNode.top();
	checkNextNode.pop();

	if ((currentNode != nullptr) && (currentNode->rightNode != nullptr))
	{
		Node* additionalNode = currentNode->rightNode;
		do
		{
			checkNextNode.push(additionalNode);
			additionalNode = additionalNode->leftNode;
		} while (additionalNode != nullptr);
	}

	return currentNode;
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
		delete child;
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

int Tree::delete_one_node(int key)
{
	Node* deletingNode = search_node_for_deleting(key, root);
	Node* parentD = search_parent_for_deleting(key, root);

	if (deletingNode->leftNode != nullptr && deletingNode->rightNode != nullptr)
	{
		Node* leftNodeD = deletingNode->leftNode;
		Node* rightNodeD = deletingNode->rightNode;

		Node* successor = minimum(deletingNode->rightNode);
		Node* parentS = search_parent_for_deleting(successor->key, deletingNode->rightNode);
		Node* rightNodeS = successor->rightNode;

		if (key < parentD->key)
		{
			parentD->leftNode = successor;
			successor->leftNode = leftNodeD;
		}
		else if (key > parentD->key)
		{
			parentD->rightNode = successor;
			successor->leftNode = leftNodeD;
		}
		else if (key == parentD->key)
		{
			root = successor;
			successor->leftNode = leftNodeD;
		}

		if (successor->key != rightNodeD->key)
		{
			successor->rightNode = rightNodeD;
		}
		if (successor->key != parentS->key)
		{
			parentS->leftNode = rightNodeS;
		}

		deletingNode->leftNode = nullptr;
		deletingNode->rightNode = nullptr;
		delete deletingNode;

		return 1;
	}

	if (deletingNode->leftNode != nullptr)
	{
		Node* leftNodeD = deletingNode->leftNode;

		if (key < parentD->key)
		{
			parentD->leftNode = leftNodeD;
		}
		else if (key > parentD->key)
		{
			parentD->rightNode = leftNodeD;
		}

		deletingNode->leftNode = nullptr;
		deletingNode->rightNode = nullptr;
		delete deletingNode;

		return 1;
	}

	if (deletingNode->rightNode != nullptr)
	{
		Node* rightNodeD = deletingNode->rightNode;

		if (key < parentD->key)
		{
			parentD->leftNode = rightNodeD;
		}
		else if (key > parentD->key)
		{
			parentD->rightNode = rightNodeD;
		}

		deletingNode->leftNode = nullptr;
		deletingNode->rightNode = nullptr;
		delete deletingNode;

		return 1;
	}

	if (key < parentD->key)
	{
		parentD->leftNode = nullptr;
	}
	else if (key > parentD->key)
	{
		parentD->rightNode = nullptr;
	}

	delete deletingNode;
	
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

void Tree::print_certain_order()
{
	std::cout << "Output of nodes in width:" << std::endl;

	Node* nodeFirst = next_node_width(true);
	if (nodeFirst == nullptr)
	{
		return;
	}

	while (nodeFirst != nullptr)
	{
		std::cout << nodeFirst->key;
		std::cout << " ";
		nodeFirst = next_node_width(false);
	}

	std::cout << std::endl << "Output of nodes in length:" << std::endl;

	Node* nodeSecond = next_node_length(true);
	if (nodeSecond == nullptr)
	{
		return;
	}

	while (nodeSecond != nullptr)
	{
		std::cout << nodeSecond->key;
		std::cout << " ";
		nodeSecond = next_node_length(false);
	}

	std::cout << std::endl << "Output of nodes in sorted order:" << std::endl;

	Node* nodeThird = next_node_sort(true);
	if (nodeThird == nullptr)
	{
		return;
	}

	while (nodeThird != nullptr)
	{
		std::cout << nodeThird->key;
		std::cout << " ";
		nodeThird = next_node_sort(false);
	}

	return;
}

void Tree::delete_binary_tree()
{
	delete root;
	root = nullptr;

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
	binaryTree.add_node(7, nullptr);
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
	int outputOne[10] = { 0 };
	int sizeOne = 10;
	std::cout << std::endl;
	binaryTree.print_binary_tree(outputOne, sizeOne);

	//Third test (Destruction)
	binaryTree.delete_one_node(6); 
	std::cout << std::endl;
	binaryTree.output(binaryTree.root);

	//
	int outputTwo[9] = { 0 };
	int sizeTwo = 9;
	std::cout << std::endl;
	binaryTree.print_binary_tree(outputTwo, sizeTwo);

	//
	std::cout << std::endl;
	binaryTree.print_certain_order();
	std::cout << std::endl;

	//
	std::cout << std::endl << "Number of existing nodes before deleting tree  - " << countNode << std::endl;
	binaryTree.delete_binary_tree();
	std::cout << std::endl << "Number of existing nodes after deleting tree - " << countNode << std::endl;
	
	return 0;
}

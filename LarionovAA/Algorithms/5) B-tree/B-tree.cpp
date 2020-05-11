
#include <iostream>

#define MINIMUM_DEGREE 2
#define MAX_KEYS (2 * MINIMUM_DEGREE - 1)
#define MAX_PTRS (2 * MINIMUM_DEGREE)
#define MIN_KEYS (MINIMUM_DEGREE - 1)
#define MIDDLE_KEY (MINIMUM_DEGREE - 1)

//For "move and find"-operations with left and right childNode
#define LEFT 1
#define RIGHT 2

static int countNode = 0;

class Node
{
public:
	int key[MAX_KEYS] = { 0 };
	Node* childNode[MAX_PTRS] = { nullptr };
	int numberNode = 0;
	bool leaf = true;
	//void* data[2 * MINIMAL_DEGREE - 1];
public:
	Node(const int key) 
	{
		this->key[0] = key;
		numberNode++;
		countNode++;
	};
	~Node() 
	{
		for (int i = 0; i < MAX_PTRS; i++)
		{
			delete childNode[i];
		}
		countNode--;
	};
};

class Tree
{
public:
	Node* root;
public:
	Tree()
	{
		root = nullptr;
	}
	~Tree() {};
private:
	Node* find_key(const int key, Node* node);

	void shift_add(const int indexKey, Node* node);
	void split_root();
	void split_node(Node* node, Node* childNode);
	void insert(const int key, Node* node);

	void shift_move(const int indicator, const int indexKey, Node* node);
	void shift_remove(const int indexKey, Node* node);
	int find_dividing_key(const int indicator, Node* node);
	bool move_key(const int indexChild, Node* node);
	Node* merge_node(const int indexKey, Node* node, Node* leftChildNode, Node* rightChildNode);
	void remove(int key, Node* node);
public:
	void search(const int key);
	int add_key(const int key);
	int delete_key(int key);
	void print_tree(Node* node);
	void delete_tree();
};


Node* Tree::find_key(const int key, Node* node)
{
	static Node* result;
	result = nullptr;

	if (node == nullptr)
	{
		return result;
	}

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if (key == node->key[i])
		{
			result = node;
			return result;
		}
	}

	for (int i = 0; i < MAX_PTRS; i++)
	{
		result = find_key(key, node->childNode[i]);
		if (result != nullptr)
		{
			break;
		}
	}

	return result;
}


void Tree::shift_add(const int indexKey, Node* node)
{
	int bufferKey = node->key[indexKey];
	int bufferKeyHelp = 0;

	for (int i = indexKey; i < (MAX_KEYS - 1); i++)
	{
		bufferKeyHelp = bufferKey;
		bufferKey = node->key[i + 1];
		node->key[i + 1] = bufferKeyHelp;
	}

	Node* bufferPtr = node->childNode[indexKey + 1];
	Node* bufferPtrHelp = nullptr;

	for (int i = (indexKey + 1); i < (MAX_PTRS - 1); i++)
	{
		bufferPtrHelp = bufferPtr;
		bufferPtr = node->childNode[i + 1];
		node->childNode[i + 1] = bufferPtrHelp;
	}

	return;
}

void Tree::split_root()
{
	Node* newChildOne = new Node(root->key[0]);
	Node* newChildTwo = new Node(root->key[MIDDLE_KEY + 1]);

	int countOne = 1;
	int countTwo = 1;

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if ((i > 0) && (i < MIDDLE_KEY))
		{
			newChildOne->key[countOne] = root->key[i];
			newChildOne->numberNode++;
			countOne++;
		}
		if (i > (MIDDLE_KEY + 1))
		{
			newChildTwo->key[countTwo] = root->key[i];
			newChildTwo->numberNode++;
			countTwo++;
		}
	}

	bool leafOne = true;
	bool leafTwo = true;
	countOne = 0;
	countTwo = 0;

	for (int i = 0; i < MAX_PTRS; i++)
	{
		if (i < MINIMUM_DEGREE)
		{
			if (root->childNode[i] != nullptr)
			{
				leafOne = false;
			}
			newChildOne->childNode[countOne] = root->childNode[i];
			countOne++;
		}
		if (i >= MINIMUM_DEGREE)
		{
			if (root->childNode[i] != nullptr)
			{
				leafTwo = false;
			}
			newChildTwo->childNode[countTwo] = root->childNode[i];
			countTwo++;
		}
	}

	newChildOne->leaf = leafOne;
	newChildTwo->leaf = leafTwo;
	
	int median = root->key[MIDDLE_KEY];

	for (int i = 0; i < MAX_KEYS ; i++)
	{
		root->key[i] = 0;
		root->numberNode--;
	}
	for (int i = 0; i < MAX_PTRS; i++)
	{
		root->childNode[i] = nullptr;
	}

	root->key[0] = median;
	root->numberNode = 1;
	root->childNode[0] = newChildOne;
	root->childNode[1] = newChildTwo;
	root->leaf = false;

	return;
}

void Tree::split_node(Node* node, Node* childNode)
{
	Node* newChild = new Node(childNode->key[MIDDLE_KEY + 1]);
	childNode->key[MIDDLE_KEY + 1] = 0;
	childNode->numberNode--;

	int count = 1;

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if (i > (MIDDLE_KEY + 1))
		{
			newChild->key[count] = childNode->key[i];
			newChild->numberNode++;
			childNode->key[i] = 0;
			childNode->numberNode--;
			count++;
		}
	}

	bool leafNewChild = true;
	count = 0;

	for (int i = 0; i < MAX_PTRS; i++)
	{
		if (i >= MINIMUM_DEGREE)
		{
			if (childNode->childNode[i] != nullptr)
			{
				leafNewChild = false;
			}
			newChild->childNode[count] = childNode->childNode[i];
			childNode->childNode[i] = nullptr;
			count++;
		}
	}

	newChild->leaf = leafNewChild;

	int median = childNode->key[MIDDLE_KEY];
	childNode->key[MIDDLE_KEY] = 0;
	childNode->numberNode--;

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if (node->key[i] == 0)
		{
			node->key[i] = median;
			node->numberNode++;
			node->childNode[i + 1] = newChild;
			break;
		}
		if (median < node->key[i])
		{
			shift_add(i, node);
			node->key[i] = median;
			node->numberNode++;
			node->childNode[i + 1] = newChild;
			break;
		}
	}

	return;
}

void Tree::insert(const int key, Node* node)
{
	if (node->leaf == true)
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			if (node->key[i] == 0)
			{
				node->key[i] = key;
				node->numberNode++;
				break;
			}
			if (key < node->key[i])
			{
				shift_add(i, node);
				node->key[i] = key;
				node->numberNode++;
				break;
			}
		}

		return;
	}

	if (node->leaf == false)
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			if (key < node->key[i])
			{
				if ((node->childNode[i])->numberNode == MAX_KEYS)
				{
					split_node(node, node->childNode[i]);
					insert(key, node);
					break;
				}

				insert(key, node->childNode[i]);
				break;
			}

			if ((key > node->key[i]) && ((node->key[i + 1] == 0) || (i == (MAX_KEYS - 1))))
			{
				if ((node->childNode[i + 1])->numberNode == MAX_KEYS)
				{
					split_node(node, node->childNode[i + 1]);
					insert(key, node);
					break;
				}

				insert(key, node->childNode[i + 1]);
				break;
			}
		}

		return;
	}

	return;
}


void Tree::shift_move(const int indicator, const int indexKey, Node* node)
{
	if (indicator == RIGHT)
	{
		for (int i = indexKey; i < (MAX_KEYS - 1); i++)
		{
			node->key[i] = node->key[i + 1];
			node->key[i + 1] = 0;
		}
		for (int i = indexKey; i < (MAX_PTRS - 1); i++)
		{
			node->childNode[i] = node->childNode[i + 1];
			node->childNode[i + 1] = nullptr;
		}
	}

	if (indicator == LEFT)
	{
		int bufferKey = node->key[indexKey];
		int bufferKeyHelp = 0;

		for (int i = indexKey; i < (MAX_KEYS - 1); i++)
		{
			bufferKeyHelp = bufferKey;
			bufferKey = node->key[i + 1];
			node->key[i + 1] = bufferKeyHelp;
		}

		Node* bufferPtr = node->childNode[indexKey];
		Node* bufferPtrHelp = nullptr;
		
		for (int i = indexKey; i < (MAX_PTRS - 1); i++)
		{
			bufferPtrHelp = bufferPtr;
			bufferPtr = node->childNode[i + 1];
			node->childNode[i + 1] = bufferPtrHelp;
		}
	}
	
	return;
}

void Tree::shift_remove(const int indexKey, Node* node)
{
	if (indexKey == (MAX_KEYS - 1))
	{
		node->childNode[indexKey + 1] = nullptr;
		return;
	}

	for (int i = indexKey; i < (MAX_KEYS - 1); i++)
	{
		node->key[i] = node->key[i + 1];
		node->key[i + 1] = 0;
	}
	for (int i = (indexKey + 1); i < (MAX_PTRS - 1); i++)
	{
		node->childNode[i] = node->childNode[i + 1];
		node->childNode[i + 1] = nullptr;
	}

	return;
}

int Tree::find_dividing_key(const int indicator, Node* node)
{
	int buffer = 0;

	if (indicator == LEFT)
	{
		if (node->leaf == true)
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				if ((i == (MAX_KEYS - 1)) || (node->key[i + 1] == 0))
				{
					buffer = node->key[i];
					break;
				}
			}
		}
		if (node->leaf == false)
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				if ((i == (MAX_KEYS - 1)) || (node->key[i + 1] == 0))
				{
					buffer = find_dividing_key(LEFT, node->childNode[i + 1]);
					break;
				}
			}
		}
	}
	if (indicator == RIGHT)
	{
		if (node->leaf == true)
		{
			buffer = node->key[0];
		}
		if (node->leaf == false)
		{
			buffer = find_dividing_key(RIGHT, node->childNode[0]);
		}
	}

	return buffer;
}

bool Tree::move_key(const int indexChild, Node* node)
{
	if ( ((indexChild + 1) < MAX_PTRS) && (node->childNode[indexChild + 1] != nullptr) && ((node->childNode[indexChild + 1])->numberNode > MIN_KEYS) )
	{
		int bufferChildKey = (node->childNode[indexChild + 1])->key[0];
		(node->childNode[indexChild + 1])->key[0] = 0;
		(node->childNode[indexChild + 1])->numberNode--;

		Node* bufferChildPtr = (node->childNode[indexChild + 1])->childNode[0];
		(node->childNode[indexChild + 1])->childNode[0] = nullptr;
		
		shift_move(RIGHT, 0, node->childNode[indexChild + 1]);

		int bufferParentKey = node->key[indexChild];
		node->key[indexChild] = bufferChildKey;

		for (int i = 0; i < MAX_KEYS; i++)
		{
			if ((node->childNode[indexChild])->key[i] == 0)
			{
				(node->childNode[indexChild])->key[i] = bufferParentKey;
				(node->childNode[indexChild])->numberNode++;
				(node->childNode[indexChild])->childNode[i + 1] = bufferChildPtr;
				break;
			}
		}

		return true;
	}

	if ( ((indexChild - 1) >= 0) && ((node->childNode[indexChild - 1])->numberNode > MIN_KEYS) )
	{
		int bufferChildKey = 0;
		Node* bufferChildPtr = nullptr;

		for (int i = 0; i < MAX_KEYS; i++)
		{
			if ( (i == (MAX_KEYS - 1)) || ((node->childNode[indexChild - 1])->key[i + 1] == 0) )
			{
				bufferChildKey = (node->childNode[indexChild - 1])->key[i];
				(node->childNode[indexChild - 1])->key[i] = 0;
				(node->childNode[indexChild - 1])->numberNode--;

				bufferChildPtr = (node->childNode[indexChild - 1])->childNode[i + 1];
				(node->childNode[indexChild - 1])->childNode[i + 1] = nullptr;
				break;
			}
		}

		int bufferParentKey = node->key[indexChild - 1];
		node->key[indexChild - 1] = bufferChildKey;

		shift_move(LEFT, 0, node->childNode[indexChild]);

		(node->childNode[indexChild])->key[0] = bufferParentKey;
		(node->childNode[indexChild])->childNode[0] = bufferChildPtr;
		(node->childNode[indexChild])->numberNode++;

		return true;
	}

	return false;
}

Node* Tree::merge_node(const int indexKey, Node* node, Node* leftChildNode, Node* rightChildNode)
{
	int median = node->key[indexKey];
	node->key[indexKey] = 0;
	node->numberNode--;

	Node* unitedNode = new Node(leftChildNode->key[0]);
	leftChildNode->key[0] = 0;
	leftChildNode->numberNode--;

	int count = 1;
	for (int i = 0; i < MAX_KEYS; i++)
	{
		if ( i > 0 && leftChildNode->key[i] != 0)
		{
			unitedNode->key[count] = leftChildNode->key[i];
			unitedNode->numberNode++;
			leftChildNode->key[i] = 0;
			leftChildNode->numberNode--;
			count++;
		}
	}

	unitedNode->key[count] = median;
	unitedNode->numberNode++;
	count++;

	for (int i = 0; i < MAX_KEYS; i++)
	{
		if (rightChildNode->key[i] != 0)
		{
			unitedNode->key[count] = rightChildNode->key[i];
			unitedNode->numberNode++;
			rightChildNode->key[i] = 0;
			rightChildNode->numberNode--;
			count++;
		}
	}

	count = 0;
	for (int i = 0; i < MAX_PTRS; i++)
	{
		if (leftChildNode->childNode[i] != nullptr)
		{
			unitedNode->childNode[count] = leftChildNode->childNode[i];
			leftChildNode->childNode[i] = nullptr;
			count++;
		}
	}
	for (int i = 0; i < MAX_PTRS; i++)
	{
		if (rightChildNode->childNode[i] != nullptr)
		{
			unitedNode->childNode[count] = rightChildNode->childNode[i];
			rightChildNode->childNode[i] = nullptr;
			count++;
		}
	}

	if (count != 0)
	{
		unitedNode->leaf = false;
	}

	delete leftChildNode;
	delete rightChildNode;

	return unitedNode;
}

void Tree::remove(int key, Node* node)
{
	if (node->leaf == true)
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			if (key == node->key[i])
			{
				node->key[i] = 0;
				node->numberNode--;
				shift_remove(i, node);

				if (root->numberNode == 0)
				{
					delete root;
					root = nullptr;
				}

				return;
			}
		}
	}

	if (node->leaf == false)
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			if (key == node->key[i])
			{
				if ((node->childNode[i])->numberNode > MIN_KEYS)
				{
					int divKey = find_dividing_key(LEFT, node->childNode[i]);
					remove(divKey, node);
					node->key[i] = divKey;
					return;
				}

				if ((node->childNode[i + 1])->numberNode > MIN_KEYS)
				{
					int divKey = find_dividing_key(RIGHT, node->childNode[i + 1]);
					remove(divKey, node);
					node->key[i] = divKey;
					return;
				}

				Node* newChild = merge_node(i, node, node->childNode[i], node->childNode[i + 1]);
				shift_remove(i, node);
				node->childNode[i] = newChild;

				if (root->numberNode == 0)
				{
					for (int i = 0; i < MAX_PTRS; i++)
					{
						root->childNode[i] = nullptr;
					}
					delete root;
					root = newChild;

					remove(key, root);
					return;
				}

				remove(key, node);
				return;
			}

			if (key < node->key[i])
			{
				if ((node->childNode[i])->numberNode <= MIN_KEYS)
				{
					bool result = move_key(i, node);

					if (result == false)
					{
						Node* newChild = merge_node(i, node, node->childNode[i], node->childNode[i + 1]);
						shift_remove(i, node);
						node->childNode[i] = newChild;

						if (root->numberNode == 0)
						{
							for (int i = 0; i < MAX_PTRS; i++)
							{
								root->childNode[i] = nullptr;
							}
							delete root;
							root = newChild;

							remove(key, root);
							return;
						}
					}

					remove(key, node);
					return;
				}

				remove(key, node->childNode[i]);
				return;
			}

			if ( (key > node->key[i]) && ((i == (MAX_KEYS - 1)) || (node->key[i + 1] == 0)) )
			{
				if ((node->childNode[i + 1])->numberNode <= MIN_KEYS)
				{
					bool result = move_key((i + 1), node);

					if (result == false)
					{
						Node* newChild = merge_node(i, node, node->childNode[i], node->childNode[i + 1]);
						shift_remove(i, node);
						node->childNode[i] = newChild;

						if (root->numberNode == 0)
						{
							for (int i = 0; i < MAX_PTRS; i++)
							{
								root->childNode[i] = nullptr;
							}
							delete root;
							root = newChild;

							remove(key, root);
							return;
						}
					}

					remove(key, node);
					return;
				}

				remove(key, node->childNode[i + 1]);
				return;
			}
		}
	}

	return;
}


void Tree::search(const int key)
{
	Node* result = find_key(key, root);

	if (result != nullptr)
	{
		std::cout << "Search was successful! " << "Node keys: ";
		for (int i = 0; i < MAX_KEYS; i++)
		{
			std::cout << result->key[i] << " ";
		}
		std::cout << ". " << "Your key: " << key << ".";
	}
	else
	{
		std::cout << "Key was not found, sorry. " << "Your key: " << key << ".";
	}

	return;
}

int Tree::add_key(const int key)
{
	if (root == nullptr)
	{
		Node* child = new Node(key);
		root = child;
		return 1;
	}

	if (root->numberNode == MAX_KEYS)
	{
		split_root();
	}

	insert(key, root);

	return 1;
}

int Tree::delete_key(int key)
{
	if (root == nullptr)
	{
		return 1;
	}

	remove(key, root);

	return 1;
}

void Tree::print_tree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	for (int i = 0; i < MAX_KEYS; i++)
	{
		std::cout << node->key[i];
		std::cout << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < MAX_PTRS; i++)
	{
		print_tree(node->childNode[i]);
	}
	
	return;
}

void Tree::delete_tree()
{
	delete root;
	root = nullptr;

	return;
}


int main()
{
	Tree BTree;

	//Adding
	const int sizeArray = 15;
	int keys[sizeArray] = { 2, 3, 1, -1, -2, -4, 4, 5, 6, -6, -8, 21, 26, -5, -3 };

	for (int i = 0; i < sizeArray; i++)
	{
		std::cout << std::endl;
		BTree.add_key(keys[i]);
		BTree.print_tree(BTree.root);
		system("pause");
	}

	//Search
	std::cout << std::endl;
	BTree.search(-6);
	std::cout << std::endl;
	BTree.search(-3);
	std::cout << std::endl;
	BTree.search(26); 
	std::cout << std::endl;
	BTree.search(-5);
	std::cout << std::endl;
	BTree.search(7); 
	std::cout << std::endl;
	
	//Deleting
	const int sizeArrayD = 15;
	int keysD[sizeArrayD] = { 26, 21, 3, 5, 4, 6, -1, -3, -2, 2, -4, -6, -8, -5, 1 };
	/*
	Order №1 - 26, 21, 3, 5, 4, 6, -1, -3, -2, 2, -4, -6, -8, -5, 1
	Order №2 - 2, 3, 1, -1, -2, -4, 4, 5, 6, -6, -8, 21, 26, -5, -3
	Order №3 - 6, -6, 1, 2, -4, -2, 3, -1, 4, 5, 26, -3, 21, -8, -5
	Copy and enjoy :)
	*/
	     
	for (int i = 0; i < sizeArrayD; i++)
	{
		std::cout << std::endl;
		BTree.delete_key(keysD[i]);
		BTree.print_tree(BTree.root);
		system("pause");
	}

	//Deleting B-tree
	std::cout << std::endl << "Number of existing nodes before deleting tree - " << countNode << std::endl;
	BTree.delete_tree();
	std::cout << std::endl << "Number of existing nodes after deleting tree - " << countNode << std::endl;

	return 1;
}

#include <iostream>
using namespace std;
#define LEN 10

class Node
{
public:
	int key;
	void* data;
	Node* left;
	Node* right;
public:
	Node(int key, void* data)
	{
		this->key = key;
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	~Node()
	{
		if (left != nullptr)
		{
			delete left;
		}
		if (right != nullptr)
		{
			delete right;
		}
	}
};

class Tree
{
public:
	Tree()
	{
		root = nullptr;
	}
	~Tree()
	{
		if (root != nullptr)
			delete root;
	}

	int add_array(int* arr, int length);

	void add_number(int key, void* data);

	void* search(int key);

	void search_and_delete(int key);

	Node* return_root()
	{
		return ((Node*)(root));
	}

	void wide_walk();

	void depth_walk();

	void from_minimum();

	void from_maximum();

private:
	Node* root;

private:
	void add_data(int key, void* data);

	void* search(int key, Node* root);

	Node* search_parent_for_new(int key, Node* root);

	Node* search_node(int key, Node* root);

	Node* search_node_parent(int key, Node* root);

	void wide_walk(Node* pri);

	void depth_walk(Node* pri);

	void from_minimum(Node* pri);

	void from_maximum(Node* pri);
};

int Tree::add_array(int* arr, int length)
{
	if (length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			add_data(arr[i], &(arr[i]));
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

void Tree::add_number(int key, void* data)
{
	add_data(key, data);
	return;
}

Node* Tree::search_parent_for_new(int key, Node* root)
{
	if (root == nullptr)
	{
		return root;
	}
	if (root->key > key)
	{
		if (root->left == nullptr)
			return root;
		return search_parent_for_new(key, root->left);
	}
	else
	{
		if (root->right == nullptr)
			return root;
		return search_parent_for_new(key, root->right);
	}
}

void Tree::add_data(int key, void* data)
{
	Node* child = new Node(key, data);
	if (root == nullptr)
	{
		root = child;
		return;
	}
	Node* parent = search_parent_for_new(key, root);
	if (parent->key > key)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}
}

void* Tree::search(int key)
{
	if (root == nullptr)
	{
		cout << "The tree is missing." << endl;
		return root;
	}
	return search_hidden(key, root);
}

void* Tree::search(int key, Node* root)
{
	if ((root->key > key) && (root->left != nullptr))
	{
		return search(key, root->left);
	}
	if ((root->key < key) && (root->right != nullptr))
	{
		return search(key, root->right);
	}
	if (root->key == key)
	{
		return root->data;
	}
	cout << "No item found." << endl;
	return nullptr;
}

//не закончена
void Tree::search_and_delete(int key)
{
	//дерево не посадили
	if (root == nullptr)
	{
		cout << "The tree is missing." << endl;
		return;
	}
	Node* del_node = search_node(key, root);
	//удаляемого элемента нет
	if (del_node == nullptr)
	{
		return;
	}
	Node* parent_del_node = search_node_parent(key, root);
	int right;
	if (parent_del_node->left->key = key)
	{
		right = 0;
	}
	else
	{
		right = 1;
	}
	Node temp(0, 0);
	//Удаляемый элемент лист
	if ((del_node->left == nullptr) && (del_node->right == nullptr))
	{
		if (right)
		{
			parent_del_node->right = nullptr;
		}
		else
		{
			parent_del_node->left = nullptr;
		}
		delete del_node;
		return;
	}
	//Если у элемента только один потомок
	if ((del_node->left == nullptr) || (del_node->right == nullptr))
	{
		if (del_node != root)
		{
			if (del_node->right != nullptr)
			{
				if (right)
				{
					parent_del_node->right = del_node->right;
					del_node->left = nullptr;
					del_node->right = nullptr;
				}
				else
				{
					parent_del_node->left = del_node->right;
					del_node->left = nullptr;
					del_node->right = nullptr;
				}

			}
			else
			{
				if (right)
				{
					parent_del_node->right = del_node->left;
					del_node->left = nullptr;
				}
				else
				{
					parent_del_node->left = del_node->left;
					del_node->left = nullptr;
				}
			}
		}
		else
		{
			if (del_node->right != nullptr)
			{
				root = del_node->right;
				del_node->left = nullptr;
				del_node->right = nullptr;
			}
			else
			{
				root = del_node->left;
				del_node->left = nullptr;
			}
		}
		delete del_node;
		return;
	}
	//Если у элемента два потомка
	temp = *parent_del_node;
	parent_del_node = del_node->right;
	if ()
		parent_del_node->left = temp.left;
	while ((del_node->left != nullptr) || (del_node->right != nullptr))
	{
		if (del_node == )
		{
			temp = *root;

		}
	}
}

Node* Tree::search_node(int key, Node* root)
{
	if ((root->key > key) && (root->left != nullptr))
	{
		return search_node(key, root->left);
	}
	else
	{
		if ((root->key < key) && (root->right != nullptr))
		{
			return search_node(key, root->right);
		}
		else
		{
			if (root->key == key)
			{
				return root;
			}
			else
			{
				return nullptr;
			}
		}
	}
}

Node* Tree::search_node_parent(int key, Node* root)
{
	if ((root == nullptr) || (root->left->key == key) || (root->right->key == key))
	{
		return root;
	}
	if ((root->key > key))
	{
		return search_node_parent(key, root->left);
	}
	else
	{
		if ((root->key < key))
		{
			return search_node_parent(key, root->right);
		}
		else
		{
			return root;
		}
	}
}

void Tree::wide_walk()
{

}

void Tree::wide_walk(Node* pri)
{

}

void Tree::depth_walk()
{
	if (root == nullptr)
	{
		cout << "The tree is missing." << endl;
		return;
	}
	depth_walk(root);
	cout << endl;
}

void Tree::depth_walk(Node* pri)
{
	cout << pri->key << "  ";
	if (pri->left != nullptr)
		depth_walk(pri->left);
	if (pri->right != nullptr)
		depth_walk(pri->right);
}

void Tree::from_minimum()
{
	if (root == nullptr)
	{
		cout << "The tree is missing." << endl;
		return;
	}
	from_minimum(root);
	cout << endl;
}

void Tree::from_minimum(Node* pri)
{
	if (pri->left != nullptr)
		from_minimum(pri->left);
	cout << pri->key << "  ";
	if (pri->right != nullptr)
		from_minimum(pri->right);
}

void Tree::from_maximum()
{
	if (root == nullptr)
	{
		cout << "The tree is missing." << endl;
		return;
	}
	from_maximum(root);
	cout << endl;
}

void Tree::from_maximum(Node* pri)
{
	if (pri->right != nullptr)
		from_minimum(pri->right);
	cout << pri->key << "  ";
	if (pri->left != nullptr)
		from_minimum(pri->left);
}

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	return;
}

void printtree(Node* root)
{
	if (root == nullptr)
	{
		cout << "No root" << endl << endl;
		return;
	}
	cout << "Root: " << root->key << ";";
	if (root->left != nullptr)
	{
		cout << "Left: " << root->left->key << ";";
	}
	else
	{
		cout << "No left;";
	}
	if (root->right != nullptr)
	{
		cout << "Right: " << root->right->key << "." << endl;
	}
	else
	{
		cout << "No right." << endl;
	}
	if (root->left != nullptr)
	{
		printtree(root->left);
	}
	if (root->right != nullptr)
	{
		printtree(root->right);
	}
}

int main()
{
	int arr[LEN] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr, LEN);
	Tree mytree;
	int err = mytree.add_array(arr, LEN);
	printtree(mytree.return_root());

	return 0;
}
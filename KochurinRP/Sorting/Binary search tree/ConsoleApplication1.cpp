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
	Node(int key1, void* data1)
	{
		key = key1;
		data = data1;
		left = nullptr;
		right = nullptr;
	}
	~Node() {};
};

class Tree
{
public:
	Tree()
	{
		root = nullptr;
	}

	int add_arr(int* arr, int length);

	void add_number(int key, void* data);

	void* search(int key);

	void search_del(int key);

	Node* return_root()
	{
		return ((Node*)(root));
	}

private:
	Node* root;

private:
	void add_data(int key, void* data);

	void* search_hidden(int key, Node* root);

	Node* search_parent_for_new(int key, Node* root);

	Node* search_node(int key, Node* root);

	Node* search_node_parent(int key, Node* root);

};

int Tree::add_arr(int* arr, int length)
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
		return root;
	}
	return search_hidden(key, root);
}

void* Tree::search_hidden(int key, Node* root)
{
	if ((root->key > key) && (root->left != nullptr))
	{
		return search_hidden(key, root->left);
	}
	if ((root->key < key) && (root->right != nullptr))
	{
		return search_hidden(key, root->right);
	}
	if (root->key == key)
	{
		return root->data;
	}
	return nullptr;
}

void Tree::search_del(int key)
{
	//дерево не посадили
	if (root == nullptr)
	{
		return;
	}
	Node* del_node = search_node(key, root);
	//удаляемого элемента нет
	if (del_node == nullptr)
		return;
	Node* parent_del_node = search_node_parent(key, root);
	//Удаляемый элемент лист
	if ((del_node->left == nullptr) && (del_node->right == nullptr))
	{
		if (parent_del_node->left->key = key)
		{
			parent_del_node->left = nullptr;
		}
		else
		{
			parent_del_node->right = nullptr;
		}
		return;
	}
	//Удаляемый элемент - корень дерева
	if (del_node == root)
	{
		Node temp(0, 0);
		temp = *(del_node); //чтобы сохранить данные о потомках
		if (del_node->right != )
			root = del_node->right;
		root->left = temp.left;
		while ((del_node->left != nullptr) || (del_node->right != nullptr))
		{
			if (del_node->right != nullptr)
			{
				if (del_node == root)
				{
					root = del_node->right;
					root->left = temp.left;
				}
				else
				{
					parent_del_node = del_node;
					parent_del_node->left = temp.left;
				}

			}
			else
			{
				parent_del_node =
			}
		}
		return;
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

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%3d  ", arr[i]);
	}
	printf("\n");
	return;
}

void printtree(Node* root)
{
	if (root == nullptr)
	{
		printf("No root\n\n");
		return;
	}
	printf("Root: %3d;", root->key);
	if (root->left != nullptr)
	{
		printf("Left: %3d;", root->left->key);
	}
	else
	{
		printf("No left;");
	}
	if (root->right != nullptr)
	{
		printf("Right: %3d.\n", root->right->key);
	}
	else
	{
		printf("No right.\n");
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
	int err = mytree.add_arr(arr, LEN);
	printtree(mytree.return_root());

	return 0;
}
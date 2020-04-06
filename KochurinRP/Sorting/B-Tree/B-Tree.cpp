//in the process		
//ready					-	need to check performance
//correctly

#include <iostream>
using namespace std;
#define LEN_NODE 2

class Node
{
public:
	int key[LEN_NODE];
	int current_length;
	void* data[LEN_NODE];
	Node* child[LEN_NODE + 1];
public:
	Node(int key, void* data)
	{
		this->current_length = 1;
		for (int i = 0; i < LEN_NODE; i++)
		{
			this->data[i] = nullptr;
			this->child[i] = nullptr;
		}
		this->key[0] = key;
		this->data[0] = data;
		this->child[LEN_NODE + 1] = nullptr;
	}
	~Node()
	{

	}
};

class B_Tree
{
public:
	B_Tree()
	{
		root = nullptr;
		width_tree = 1;
	}
	~B_Tree()
	{
		if (root != nullptr)
			delete root;
	}

	int add_array(int* arr, int length);

	void add_number(int key, void* data);

private:
	Node* root;

	int width_tree;

private:
	void add_data(int key, void* data);

	bool search_place(int key, Node** record, int width);

	void new_node(int key, void* data, Node* record_parent);
};

//correctly
int B_Tree::add_array(int* arr, int length)
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

//correctly
void B_Tree::add_number(int key, void* data)
{
	add_data(key, data);
	return;
}

//in the process
void B_Tree::add_data(int key, void* data)
{
	if (root == nullptr)
	{
		root = new Node(key, data);
		return;
	}
	Node* node_record = root;
	bool child = search_place(key, &node_record, 1);
	if (child == true)
	{
		new_node(key, data, node_record);
		return;
	}
}

//ready
/*поиск Node'а, в который необходимо записать новую запись.
Возвращает true, если необходимо записать в потомка, которого ещё нет*/
bool B_Tree::search_place(int key, Node** record, int width)
{
	if (width == width_tree)
	{
		return false;
	}
	if ((*record)->key[0] >= key)
	{
		*record = (*record)->child[0];
		return search_place(key, record, width + 1);
	}
	for (int i = 0; i < LEN_NODE - 1; i++)
	{
		if ((*record)->current_length <= i + 1)
		{
			return false;
		}
		if (((*record)->key[i] <= key) && ((*record)->key[i + 1] >= key))
		{
			if ((*record)->child[i + 1] == nullptr)
			{
				return true;
			}
			*record = (*record)->child[i + 1];
			return search_place(key, record, width + 1);
		}
	}
	if ((*record)->key[LEN_NODE - 1] < key)
	{
		if ((*record)->child[LEN_NODE] == nullptr)
		{
			return true;
		}
		else
		{
			*record = (*record)->child[LEN_NODE];
			return search_place(key, record, width + 1);
		}
	}
}

//ready
//добавление потомка, который не был создан, но глубина дерева позволяет
void B_Tree::new_node(int key, void* data, Node* record_parent)
{
	int number_parent = 1;
	if (key > record_parent->key[LEN_NODE - 1])
	{
		number_parent = LEN_NODE;
	}
	else
	{
		while ((key > record_parent->key[number_parent]) && (number_parent < LEN_NODE))
		{
			number_parent++;
		}
	}
	record_parent->child[number_parent] = new Node(key, data);
	return;
}

void printarr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}

//in the process
//программа из бинарного дерева
//void printtree(Node* root)
//{
//	if (root == nullptr)
//	{
//		cout << "No tree" << endl << endl;
//		return;
//	}
//	cout << "Root: " << root->key << ";";
//	if (root->left != nullptr)
//	{
//		cout << "Left: " << root->left->key << ";";
//	}
//	else
//	{
//		cout << "No left;";
//	}
//	if (root->right != nullptr)
//	{
//		cout << "Right: " << root->right->key << "." << endl;
//	}
//	else
//	{
//		cout << "No right." << endl;
//	}
//	if (root->left != nullptr)
//	{
//		printtree(root->left);
//	}
//	if (root->right != nullptr)
//	{
//		printtree(root->right);
//	}
//}

int main()
{
	int arr[10] = { 51, -7, 5, 36, 74, 68, 88, 4, 9, -88 };
	printarr(arr, 10);
	B_Tree mytree;
	mytree.add_array(arr, 10);
	return 0;
}
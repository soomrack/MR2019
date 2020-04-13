//in the process		
//ready					-	need to check performance
//correctly

#include <iostream>
using namespace std;
#define LEN_NODE 2

class Node
{
public:
	int key[LEN_NODE + 1];
	int current_length;
	void* data[LEN_NODE + 2];
	Node* child[LEN_NODE + 2];
public:
	Node()
	{
		this->current_length = 0;
		for (int i = 0; i <= LEN_NODE + 1; i++)
		{
			this->data[i] = nullptr;
			this->child[i] = nullptr;
		}
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

	void search_place(int key, Node** record, int width);

	void write_to_node(int key, void* data, Node* record);

	void overflow(Node* record);

	Node* search_parent(Node* child, Node* parent);

	void split_into_two(Node* initially, Node* right);
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

//ready
void B_Tree::add_data(int key, void* data)
{
	//не посадили
	if (root == nullptr)
	{
		root = new Node();
		root->key[0] = key;
		root->data[0] = data;
		root->current_length = 1;
		return;
	}
	//поиск места записи
	Node* node_record = root;
	search_place(key, &node_record, 1);
	if (node_record == nullptr)
	{
		return;
	}
	//функция записи данных
	write_to_node(key, data, node_record);
	return;
}

//ready
void B_Tree::write_to_node(int key, void* data, Node* record)
{
	//поиск места записи
	int will_displace_with = 0;
	int flaq = 1;
	if (key <= record->key[0])
	{
		will_displace_with = 0;
		flaq--;
	}
	else
	{
		for (int i = 1; i < record->current_length; i++)
		{
			if ((record->key[i - 1] < key) && (record->key[i] >= key))
			{
				will_displace_with = i;
				flaq--;
			}
		}
		if (record->key[record->current_length - 1] < key)
		{
			will_displace_with = record->current_length;
			flaq--;
		}
	}
	if (flaq != 0)
	{
		cout << "error finding record location. flaq = " << flaq;
		return;
	}
	//смещение записей вправо
	for (int i = (record->current_length); i > will_displace_with; i--)
	{
		record->key[i] = record->key[i - 1];
		record->data[i] = record->data[i - 1];
	}
	//непосредственная запись
	record->key[will_displace_with] = key;
	record->data[will_displace_with] = data;
	record->current_length++;
	//проверка на переполнение
	if (record->current_length > LEN_NODE)
	{
		overflow(record);
	}
	return;
}

//in the process
void B_Tree::overflow(Node* record)
{
	//когда переполнен корень
	if (record = root)
	{
		Node* left = root;
		Node* right = new Node;
		split_into_two(left, right);
		root = new Node;
		root->child[0] = left;
		root->child[1] = right;
		root->key[0] = left->key[(LEN_NODE - 1) / 2 + 1];
		root->data[0] = left->data[(LEN_NODE - 1) / 2 + 1];
		root->current_length = 1;
		left->data[(LEN_NODE - 1) / 2 + 1] = nullptr;
		left->current_length--;
		return;
	}
	Node* parent = search_parent(record, root);
	//в случае ошибки поиска родителя
	if (parent == nullptr)
	{
		return;
	}
	//ищем номер ребёнка
	int child_number;

}

//ready
//initially по совместительству и left
void B_Tree::split_into_two(Node* initially, Node* right)
{
	int middle = (LEN_NODE - 1) / 2 + 1;// для двух в одном node'е середина будет 1, 3 - 2, 4 - 2, 5 - 3, 6 - 3 и т.д.
	for (int i = (middle + 1); i <= LEN_NODE; i++)
	{
		right->key[i - (middle + 1)] = initially->key[i];
		(initially->current_length)--;
		(right->current_length)++;
		right->data[i - (middle + 1)] = initially->data[i];
		initially->data[i] = nullptr;
		right->child[i - (middle + 1)] = initially->child[i];
		initially->child[i] = nullptr;
	}
	right->child[LEN_NODE - middle] = initially->child[LEN_NODE + 1];
	initially->child[LEN_NODE + 1] = nullptr;
	return;
}

//ready
Node* B_Tree::search_parent(Node* child, Node* parent)
{
	if (parent->key[0] >= child->key[0])
	{
		return search_parent(child, parent->child[0]);
	}
	for (int i = 1; i < parent->current_length; i++)
	{
		if ((parent->key[i - 1] < child->key[0]) && (parent->key[i]) >= child->key[0])
		{
			return search_parent(child, parent->child[i]);
		}
	}
	if (parent->key[parent->current_length - 1] < child->key[0])
	{
		return search_parent(child, parent->child[parent->current_length]);
	}
	cout << "error finding parent";
	return nullptr;
}

//ready
//поиск Node'а, в который необходимо записать новую запись.
void B_Tree::search_place(int key, Node** record, int width)
{
	if (width == width_tree)
	{
		return;
	}
	if ((*record)->key[0] >= key)
	{
		*record = (*record)->child[0];
		return search_place(key, record, width + 1);

	}
	for (int i = 1; i < (*record)->current_length; i++)
	{
		if (((*record)->key[i - 1] < key) && ((*record)->key[i]) >= key)
		{
			*record = (*record)->child[i];
			return search_place(key, record, width + 1);
		}
	}
	if ((*record)->key[((*record)->current_length - 1)] < key)
	{
		*record = (*record)->child[((*record)->current_length)];
		return search_place(key, record, width + 1);
	}
	*record = nullptr;
	cout << "error in finding a search place";
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

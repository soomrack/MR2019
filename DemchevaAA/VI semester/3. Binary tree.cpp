#include <iostream>
#include <queue>
using namespace std;

class Node //Узел
{
public:
	int key; //Ключ - метка, по которой мы ищем данные в дереве
	void* data;//Указатель на сами данные
	Node* left_child; //Указатель на левого потомка
	Node* right_child;//Указатель на правого потомка

public:
	Node(int key, void* data);//Конструктор

	~Node() {};//Деструктор
};

Node::Node(const int key, void* data)  //Конструктор - функция формирования узла
{
	this->key = key;
	this->data = data;
	left_child = nullptr;
	right_child = nullptr;
}


class Tree //Дерево
{
public:
	Node* root; //Узел-корень

public:
	Tree() //Конструктор - функция формирования дерева
	{
		root = nullptr;
	}
	~Tree() {};//Деструктор

public:
	int add_data(int key, void* data); //Функция добавления данных в дерево

private:
	Node* search_parent_for_new_node(int key, Node* root); //Функция поиска места для нового узла

private:
	Node* next_node(bool restart);

public:
	void print();
};


Node* Tree::search_parent_for_new_node(int key, Node* root) {
	if (root->key <= key) {   //Если ключ текущего узла меньше/равен ключу корня
		if (root->left_child == nullptr) return root; //И если у корня отсутствует левый ребенок - возвращаем корень
		return search_parent_for_new_node(key, root->left_child);//Если у корня есть левый ребенок, принимаем его за родителя и продолжаем поиск
	}
	//Иначе - если ключ текущего узла больше
	if (root->right_child == nullptr) return root; //и если у корня нет правого ребенка - возврашаем корень
	return search_parent_for_new_node(key, root->right_child); //если есть, принимаем его за родителя и продолжаем поиск
}

int Tree::add_data(int key, void* data)//функция добавления данных в дерево
{
	Node* child = new Node(key, data); //создаем новый узел

	if (root == nullptr) { //если нет корня, принимаем новый за него
		root = child;
		return 1;
	}

	Node* parent = search_parent_for_new_node(key, root); //ищем родителя для нового узла

	if (key <= parent->key) { //если ключ текущего узла меньше/равен ключу найденного родителя
		parent->left_child = child;//помещаем дочений узел слева
	}
	else {
		parent->right_child = child;// иначе - справа
	}
	return 1;
}

Node* Tree:: next_node(bool restart)
{
	static bool on_the_way = true; //Флаг - обход уже был начат
	static queue <Node*> queue_for_printing; //создаем очередь - в таком порядке будем выводить элементы
	if (restart == false)
	{ 
		queue_for_printing.pop(); 
	}
	Node* current_node = queue_for_printing.front();
	
	return current_node;
}

void Tree::print()
{
	while (node = root_node())
	{
		node.print();
	}
}



int main()
{
	Tree mytree = Tree();

	mytree.add_data(5, nullptr);
	mytree.add_data(1, nullptr);
	mytree.add_data(3, nullptr);
	mytree.add_data(9, nullptr);
	mytree.add_data(5, nullptr);
	mytree.add_data(8, nullptr);
	mytree.add_data(4, nullptr);




}
//redunent - удаляемый узел
//1. обход в ширину Breadth  BSF
//2. обход в глубину Deep search first DSF
//3. вывести по порядку



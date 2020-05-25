#include <iostream>
#include "TreeMethods.h"

using namespace std;

Node::Node()	//конструктор узла, все пустое
{
	for (int i = 0; i < t; i++) elements[i] = 0;		
	for (int i = 0; i < t+1; i++) child[i] = nullptr;
	parent = nullptr;
}

Tree::Tree()            //создание дерева
{
	root = nullptr;
}


void Tree::add_element(int key)
{
	if (root == nullptr)		//если деерво пустое
	{
		Node* node = new Node();
		node->elements[0] = key;
		node->parent = nullptr;
		this->root = node;
		return;
	}

	//если не пустое, то ищем лист куда вставляется новый ключ
	Node* leaf_for_insert = search_leaf_for_new_key(root, key);	

	//если лист не полный, то просто вставляем
	if (count_key_amount(leaf_for_insert) < t)
	{
		insert_key(leaf_for_insert, key, nullptr);
	}
	//если лист заполнен, то разделяем этот лист на 2
	else
	{
		split(leaf_for_insert);	//разделяем узел, дерево перестраивается
		leaf_for_insert = search_leaf_for_new_key(root, key);	//заново ищем нужный лист
		insert_key(leaf_for_insert, key, nullptr);		// вставляем
	}
}

int Tree::count_children_amount(Node* node)
{
	int children_amount = 0;
	for (int i = 0; i < t+1; i++)
		if (node->child[i] != nullptr) children_amount++;
	return children_amount;
}

int Tree::count_key_amount(Node* node)
{
	int key_amount = 0;
	for (int i = 0; i < t; i++)
		if (node->elements[i] != 0) key_amount++;
	return key_amount;
}

Node* Tree::search_leaf_for_new_key(Node* root, int key)
{
	if (count_children_amount(root) == 0) 
	{
		return root;
	}
	else
	{
		int i = 0;
		while ((key > root->elements[i]) && (root->elements[i] != 0) && (i<t)) i++;
		return search_leaf_for_new_key(root->child[i], key);
	}
}

void Tree::insert_key(Node* node, int key, Node* add_child)		
{
	int insert_index = 0;
	while ((key > node->elements[insert_index]) && (node->elements[insert_index] != 0)) insert_index++;
	shift_elements_and_children(node, insert_index); // сдвигаем ключи и детей вправо
	node->elements[insert_index] = key; // вставляем новый ключ

	if (add_child != nullptr)
	{
		node->child[insert_index + 1] = add_child;
	}
}

void Tree::shift_elements_and_children(Node* node, int start)	//сдвиг начиная со start всех элементов впрво
{
	for (int i = t-1; i > start; i--)
	{
		node->elements[i] = node->elements[i - 1];
	}
	if (count_children_amount(node) != 0)
	{
		for (int i = t; i > start+1; i--)
		{
			node->child[i] = node->child[i - 1];
		}
	}
}

void Tree::print_tree(Node* root) // вывод дерева в глубину
{
	for (int i = 0; i < t; i++)
		cout << root->elements[i] << ' ';

	cout << endl;

	int current_children_amount = count_children_amount(root);
	if (current_children_amount)
	{
		for (int i = 0; i < current_children_amount; i++)
			print_tree(root->child[i]);
	}
}

void Tree::split(Node* node)
{
	//случай когда разделяемый узел на самом верху
	if (node->parent == nullptr)		
	{
		Node* new_node_right = new Node();	//новый узел справа 
		copy_data_to_right_node(node, new_node_right); //копируем все данные из текущего узла в новый правый

		Node* new_node_top = new Node();	//новый верхний
		copy_data_to_top_node(node, new_node_top, new_node_right); //копируем в новый верхний центральынй элемент

		new_node_right->parent = node->parent;

		delete_data_left_node(node);	//удаляем данные о центральном элементе и новом правом узле
	}
	else //случай когда над разделяемом узлом есть еще один
	{
		if (count_key_amount(node->parent) == t) //если в узле выше нет места, то его тоже делим
		{
			split(node->parent);

		}

		Node* new_node_right = new Node();	//новый узел справа (тут ваще все правитьпод параметр t)
		copy_data_to_right_node(node, new_node_right); //копируем все данные из текущего узла в новый правый
		new_node_right->parent = node->parent;

		//if (node->parent->child[0] != 0 && node->parent != nullptr)
		//{
		//	for (int i = 0; i < count_children_amount(node->parent); i++)
		//	{
		//		node->parent->child[i]->parent = new_node_right;
		//	}
		//}

		//средний элемент выкидываем вверх
		insert_key(node->parent, node->elements[t / 2], new_node_right);


		//удаляем данные о центральном элементе и новом правом узле
		delete_data_left_node(node);
	}
}

void Tree::copy_data_to_right_node(Node* node, Node* new_node_right)
{
	for (int i = t/2+1; i < t ; i++)
	{
		new_node_right->elements[i-(t/2+1)] = node->elements[i];
		new_node_right->child[i-(t/2+1)] = node->child[i];	
//		node->child[i]->parent = new_node_right;
	}
	new_node_right->child[t/2] = node->child[t];
}

void Tree::copy_data_to_top_node(Node* node, Node* new_node_top, Node* new_node_right)
{
	node->parent = new_node_top;
	new_node_top->elements[0] = node->elements[t / 2];
	new_node_top->child[0] = node;
	root = new_node_top;
	new_node_top->child[1] = new_node_right;

}

void Tree::delete_data_left_node(Node* node)
{
	for (int i = t - 1; i >= t/2; i--)		
	{
		node->elements[i] = 0;
		node->child[i + 1] = nullptr;
	}
}

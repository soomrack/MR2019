#include <iostream>
#include <queue> 

#include"treeMethods.h"

using namespace std;

Node::Node(int key, int data)   //создание узла 
{
    this->key = key;
    this->data = data;
    left_child = nullptr;
    right_child = nullptr;
}

Tree::Tree()            //создание дерева
{
    root = nullptr;
}

Node* Tree::search_parent_for_new_child(int key, Node* root)
{
    if (root->key > key)
    {
        if (root->left_child == nullptr) return root;
        else return search_parent_for_new_child(key, root->left_child);
    }

    if (root->key <= key)
    {
        if (root->right_child == nullptr) return root;
        else return search_parent_for_new_child(key, root->right_child);
    }
}

void Tree::add_node(int key, int data)  //добавить узел
{
    Node* child = new Node(key, data);

    if (root == nullptr)        
    {
        root = child;
        return;
    }

    Node* parent = search_parent_for_new_child(key, root);

    if (key <= parent->key) parent->left_child = child;
    else parent->right_child = child;
    return;
}

void Tree::print_tree_dsf(Node* root)       //вывод дерева в глубину (начинается влево)
{
    if (root != nullptr)
    {
        cout << root->key << '\n';
        print_tree_dsf(root->left_child);
        print_tree_dsf(root->right_child);
    }
}

void Tree::delete_node(Node* root, int key)
{

    Node* remove_node = search_node(root, key);
    Node* parent_of_remove_node = search_parent_of_node(root, key);


    if (remove_node->left_child == nullptr && remove_node->right_child == nullptr)   // у удаляемоего узла нет детей
    {
        if (parent_of_remove_node->left_child == remove_node)
        {
            parent_of_remove_node->left_child = nullptr;
        }
        else
        {
            parent_of_remove_node->right_child = nullptr;
        }
    }

    if (remove_node->left_child == nullptr && remove_node->right_child != nullptr)   //у удаляемого узла только правый ребенок
    {
        if (parent_of_remove_node->left_child == remove_node)
        {
            parent_of_remove_node->left_child = remove_node->right_child;
        }
        else
        {
            parent_of_remove_node->right_child = remove_node->right_child;
        }
    }

    if (remove_node->left_child != nullptr && remove_node->right_child == nullptr)   //у удаляемого узла только левый ребенок
    {
        if (parent_of_remove_node->left_child == remove_node)
        {
            parent_of_remove_node->left_child = remove_node->left_child;
        }
        else
        {
            parent_of_remove_node->right_child = remove_node->left_child;
        }
    }

    if (remove_node->left_child != nullptr && remove_node->right_child != nullptr)   //у удаляемого узла 2 ребенока
    {
        Node* replace_node = find_min(remove_node->right_child);

        if (replace_node->right_child == nullptr)
        {
            copy_and_delete_node(replace_node, remove_node);        //у минимального узла нет правого ребенка
        }
        else
        {
            copy_node(replace_node, remove_node);               //у минимального узла есть правый ребенок
            copy_and_delete_node(replace_node->right_child, replace_node);
        }
    }
}

Node* Tree::find_min(Node* root)        //поиск минимума начиная с заданного корня
{
    if (root->left_child == nullptr)
    {
        return root;
    }
    else
    {
        return find_min(root->left_child);
    }
}

void Tree::copy_node(Node* from, Node* to)       //просто копирует из from в to
{
    to->key = from->key;
    to->data = from->data;
}

void Tree::copy_and_delete_node(Node* from, Node* to)      //копирует из from в to и удаляет from
{
    int key_buffer = from->key;
    int data_buffer = from->data;
    delete_node(root, from->key);
    to->key = key_buffer;
    to->data = data_buffer;
}

Node* Tree::search_node(Node* root, int key)    //поиск в глубину
{
    if (root == nullptr) return root;

    if (root->key == key) return root;
    else if (root->key > key) return search_node(root->left_child, key);
    else return search_node(root->right_child, key);

}

Node* Tree::search_parent_of_node(Node* root, int key)      //поиск родителя узла по ключу узла
{
    if (root == nullptr) return root;

    if (root->right_child != nullptr && root->right_child->key == key) return root;
    if (root->left_child != nullptr && root->left_child->key == key) return root;

    else if (root->key > key) return search_parent_of_node(root->left_child, key);
    else return search_parent_of_node(root->right_child, key);

}

void Tree::print_tree_bsf(Node* root)       //вывод дерева в консоль в ширину
{
    queue <Node*> elements;
    elements.push(root);

    while (!elements.empty())
    {
        Node* buffer = elements.front();
        cout << buffer->key << endl;
        elements.pop();

        if (buffer->left_child != nullptr)
        {
            elements.push(buffer->left_child);
        }
        if (buffer->right_child != nullptr)
        {
            elements.push(buffer->right_child);
        }
    }
}

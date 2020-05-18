#ifndef TREEMETHODS_H
#define TREEMETHODS_H

#include <iostream>


class Node
{
public:
    int key;
    int data;       //пока int, потом поменять на void*
    Node* left_child;
    Node* right_child;
public:
    Node(int key, int data);
};

class Tree
{
public:
    Node* root;
    Tree();
public:
    void add_node(int key, int data);
    void delete_node(Node* root, int key);
    void print_tree_dsf(Node* root);
    void print_tree_bsf(Node* root);
    Node* search_node(Node* root, int key);
private:
    Node* search_parent_of_node(Node* root, int key);
    Node* search_parent_for_new_child(int key, Node* root);
    Node* find_min(Node* root);
    void copy_node(Node* from, Node* to);
    void copy_and_delete_node(Node* from, Node* to);
};

#endif 
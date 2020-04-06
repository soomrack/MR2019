#ifndef THREE_TREE_H
#define THREE_TREE_H

using namespace std;
#include <algorithm>
#include <stack>
#include <iostream>

class Tree {
public:
    Tree();

    virtual ~Tree();

private:
    //описание структуры узла с сылками на детей
    struct Node {
        int key_;        // значение ключа, содержащееся в узле
        Node *left_;    // указатель на левое поддерево
        Node *right_;   // указатель на правое поддерево
        Node *p_;       // указатель на  родителя
        void *data;

        //Конструктор узла
        Node(int key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr, void *data = nullptr);

        ~Node() = default;
    };

    Node *root_;

    void deleteSubtree(Node *node);

    Node *searchNode(int key);

    void insert(int key);

    void deleteKey(int key);

};

#endif //THREE_TREE_H

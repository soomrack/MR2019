#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "Node.h"


class Tree {
private:
    Node *root;

public:
    Tree();

    ~Tree() = default;;

    void push(int key, void *data);

    void *pull(int key);

    void *findFor(int key);

    void printTree();

    static Node *maxNode(Node *localRoot);

    static Node *minNode(Node *localRoot);

private:
    Node *search(int key);

    static Node *localSearch(int key, Node *localRoot);

    static Node *findParentForNewNode(int key, Node *aRoot);

    static void printLocalTree(Node *localRoot);

    static bool pullIfNoChildren(Node *removable, Node *parent);

    static bool pullIfNoLeftChild(Node *removable, Node *parent);

    static bool pullIfNoRightChild(Node *removable, Node *parent);

    static bool pullIfHaveChildren(Node *removable, Node *parent);

    static Node *parentSearch(int childKey, Node *localRoot);
};


#endif //BINARYTREE_TREE_H

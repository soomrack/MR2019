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

private:
    Node *search(int key);

    static Node *localSearch(int key, Node *localRoot);

    static Node *findParentForNewNode(int key, Node *aRoot);

    static void printLocalTree(Node *localRoot);

    static Node *parentSearch(int childKey, Node *localRoot);

    static void *pullRightChild(Node *parentOfRemovable);

    static void *pullLeftChild(Node *parentOfRemovable);

    static Node *localMinNode(Node *localRoot);

    void *pullRoot();
};


#endif //BINARYTREE_TREE_H

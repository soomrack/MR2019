#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

#include "InnerNode.h"


class Node {
private:
    InnerNode innerNode;

public:
    Node() = default;

    Node(int key, void *data);

    ~Node() = default;;

    int getKey();

    void *getData();

    Node *getLeftChild();

    Node *getRightChild();

    void setKey(int aKey);

    void setData(void *aData);

    void setLeftChild(Node *aLeftChild);

    void setRightChild(Node *aRightChild);
};


#endif //BINARYTREE_NODE_H

#ifndef BINARYTREE_INNERNODE_H
#define BINARYTREE_INNERNODE_H

#include "Node.h"


class InnerNode {
private:
    int key;
    void *data;
    Node *leftChild;
    Node *rightChild;

public:
    InnerNode();

    InnerNode(int key, void *data);

    ~InnerNode() = default;;

    int getKey();

    void *getData();

    Node *getLeftChild();

    Node *getRightChild();

    void setKey(int aKey);

    void setData(void *aData);

    void setLeftChild(Node *aLeftChild);

    void setRightChild(Node *aRightChild);
};


#endif //BINARYTREE_INNERNODE_H

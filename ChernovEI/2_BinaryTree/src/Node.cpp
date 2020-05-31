#include "Node.h"

Node::Node(int key, void *data) {
    this->key = key;
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

int Node::getKey() {
    return key;
}

Node *Node::getLeftChild() {
    return leftChild;
}

Node *Node::getRightChild() {
    return rightChild;
}

void *Node::getData() {
    return data;
}

void Node::setKey(int aKey) {
    key = aKey;
}

void Node::setLeftChild(Node *aLeftChild) {
    leftChild = aLeftChild;
}

void Node::setRightChild(Node *aRightChild) {
    rightChild = aRightChild;
}

void Node::setData(void *aData) {
    data = aData;
}

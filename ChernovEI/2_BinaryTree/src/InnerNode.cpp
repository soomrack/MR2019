#include "InnerNode.h"


InnerNode::InnerNode() {
    this->key = 0;
    this->data = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

InnerNode::InnerNode(int key, void *data) {
    this->key = key;
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

int InnerNode::getKey() {
    return key;
}

Node *InnerNode::getLeftChild() {
    return leftChild;
}

Node *InnerNode::getRightChild() {
    return rightChild;
}

void *InnerNode::getData() {
    return data;
}

void InnerNode::setKey(int aKey) {
    key = aKey;
}

void InnerNode::setLeftChild(Node *aLeftChild) {
    leftChild = aLeftChild;
}

void InnerNode::setRightChild(Node *aRightChild) {
    rightChild = aRightChild;
}

void InnerNode::setData(void *aData) {
    data = aData;
}

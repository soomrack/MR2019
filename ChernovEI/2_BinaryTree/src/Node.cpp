#include "Node.h"


Node::Node(int key, void *data) {
    innerNode = new InnerNode(key, data);
}

int Node::getKey() {
    innerNode.getKey();
}

Node *Node::getLeftChild() {
    innerNode.getLeftChild();
}

Node *Node::getRightChild() {
    innerNode.getRightChild();
}

void *Node::getData() {
    innerNode.getData();
}

void Node::setKey(int aKey) {
    innerNode.setKey(aKey);
}

void Node::setLeftChild(Node *aLeftChild) {
    innerNode.setLeftChild(aLeftChild);
}

void Node::setRightChild(Node *aRightChild) {
    innerNode.setRightChild(aRightChild);
}

void Node::setData(void *aData) {
    innerNode.setData(aData);
}

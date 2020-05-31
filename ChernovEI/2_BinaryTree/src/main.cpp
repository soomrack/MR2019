#include "Tree.h"

#include <iostream>

using namespace std;


void Tree::printTree() {
    if (root == nullptr) {
        return;
    }
    cout << "Key: " << root->getKey() << "; " << "Data" << root->getData() << endl;
    printLocalTree(root->getLeftChild());
    printLocalTree(root->getRightChild());
}

void Tree::printLocalTree(Node *localRoot) {
    if (localRoot == nullptr) {
        return;
    }
    if (localRoot->getData() != nullptr) {
        cout << "Key: " << localRoot->getKey() << "; " << "Data: " << localRoot->getData() << endl;
    }
    printLocalTree(localRoot->getLeftChild());
    printLocalTree(localRoot->getRightChild());
}

int main() {
    int a0 = 0;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    int a4 = 4;
    int b1 = -1;
    int b2 = -2;
    int b3 = -3;
    int b4 = -4;

    Tree tree = Tree();
    tree.push(0, &a0);
    tree.push(3, &a3);
    tree.push(4, &a4);
    tree.push(1, &a1);
    tree.push(2, &a2);
    tree.push(-2, &b2);
    tree.push(-1, &b1);
    tree.push(-4, &b4);
    tree.push(-3, &b3);
    cout << tree.pull(0) << endl;
    tree.printTree();
}

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
        cout << "Key: " << localRoot->getKey() << "; " << "Data" << localRoot->getData() << endl;
    }
    printLocalTree(localRoot->getLeftChild());
    printLocalTree(localRoot->getRightChild());
}

int main() {
    Tree tree = Tree();
    tree.push(1, -11);
    tree.push(-1, 11);
    tree.push(2, &22);
    tree.push(-3, -33);
    tree.push(-2, -22);
    tree.push(-5, -55);
    tree.push(-4, -44);
    tree.push(1, -11);
    cout << tree.pull(1) << endl;
    tree.printTree();
}

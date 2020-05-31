#include <iostream>
#include "Tree.h"

using namespace std;


Tree::Tree() {
    this->root = nullptr;
}

void *Tree::findFor(int key) {
    return search(key)->getData();
}

/**
 * @return nullptr if key is not found
 * */
Node *Tree::search(int key) {
    if (root == nullptr) {
        cout << "The key is not found!" << endl;
        return nullptr;
    }
    if (root->getKey() == key) {
        return root;
    } else if (root->getKey() < key) {
        return localSearch(key, root->getRightChild());
    } else {
        return localSearch(key, root->getRightChild());
    }
}

Node *Tree::localSearch(const int key, Node *localRoot) {
    if (localRoot == nullptr) {
        cout << "The key is not found!" << endl;
        return nullptr;
    }
    if (localRoot->getKey() == key) {
        return localRoot;
    } else if (localRoot->getKey() < key) {
        return localSearch(key, localRoot->getRightChild());
    } else {
        return localSearch(key, localRoot->getRightChild());
    }
}

void Tree::push(const int key, void *data) {
    if (root == nullptr) {
        Node *child = new Node(key, data);
        root = child;
        return;
    }
    Node *parent = findParentForNewNode(key, root);
    Node *child = new Node(key, data);
    if (parent->getKey() < key) {
        parent->setRightChild(child);
        return;
    }
    parent->setLeftChild(child);
}

Node *Tree::findParentForNewNode(const int key, Node *aRoot) {
    if (aRoot->getKey() < key) {
        if (aRoot->getRightChild() == nullptr) {
            return aRoot;
        }
        return findParentForNewNode(key, aRoot->getRightChild());
    }
    if (aRoot->getLeftChild() == nullptr) {
        return aRoot;
    }
    return findParentForNewNode(key, aRoot->getLeftChild());
}

/**
 * @return parent
 * */
Node *Tree::parentSearch(int childKey, Node *localRoot) {
    if (localRoot == nullptr) {
        cout << "The key is not found!" << endl;
        return nullptr;
    }
    if (localRoot->getLeftChild()->getKey() == childKey || localRoot->getRightChild()->getKey() == childKey) {
        return localRoot;
    } else if (localRoot->getKey() < childKey) {
        return localSearch(childKey, localRoot->getRightChild());
    } else {
        return localSearch(childKey, localRoot->getRightChild());
    }
}

/**
 * @return nullptr if key is not found (or error)
 * */
void *Tree::pull(const int key) {
    Node *parent = parentSearch(key, root);
    void *res;

    if (parent == nullptr) {
        if (root->getKey() == key) {
            return pullRoot();
        }
        return nullptr;
    }

    if (parent->getKey() < key) {
        res = pullRightChild(parent);
    } else {
        res = pullLeftChild(parent);
    }

    if (res != nullptr) {
        return res;
    }
    cout << "Something went wrong ':D" << endl;
    return nullptr;
}

void *Tree::pullRightChild(Node *parentOfRemovable) {
    Node *removable = parentOfRemovable->getRightChild();
    Node *minNode = nullptr;

    if (removable->getRightChild() == nullptr) {
        if (removable->getLeftChild() == nullptr) {
            parentOfRemovable->setRightChild(nullptr);
            return removable->getData();
        }
        parentOfRemovable->setRightChild(removable->getLeftChild());
        return removable->getData();
    }
    if (removable->getLeftChild() == nullptr) {
        parentOfRemovable->setRightChild(removable->getRightChild());
        return removable->getData();
    }

    minNode = localMinNode(removable->getRightChild());
    minNode->setLeftChild(removable->getLeftChild());
    parentOfRemovable->setRightChild(removable->getRightChild());
    return removable->getData();
}

void *Tree::pullLeftChild(Node *parentOfRemovable) {
    Node *removable = parentOfRemovable->getLeftChild();
    Node *minNode = nullptr;

    if (removable->getRightChild() == nullptr) {
        if (removable->getLeftChild() == nullptr) {
            parentOfRemovable->setLeftChild(nullptr);
            return removable->getData();
        }
        parentOfRemovable->setLeftChild(removable->getLeftChild());
        return removable->getData();
    }
    if (removable->getLeftChild() == nullptr) {
        parentOfRemovable->setLeftChild(removable->getRightChild());
        return removable->getData();
    }

    minNode = localMinNode(removable->getRightChild());
    minNode->setLeftChild(removable->getLeftChild());
    parentOfRemovable->setLeftChild(removable->getRightChild());
    return removable->getData();
}

Node *Tree::localMinNode(Node *localRoot) {
    if (localRoot->getLeftChild() == nullptr) {
        return localRoot;
    }
    return localMinNode(localRoot->getLeftChild());
}

void *Tree::pullRoot() {
    void *rootData = root->getData();
    if (root->getRightChild() != nullptr) {
        if (root->getLeftChild() == nullptr) {
            root = root->getRightChild();
            return rootData;
        }
        Node *minNode = localMinNode(root->getRightChild());
        minNode->setLeftChild(root->getLeftChild());
        root = root->getRightChild();
        return rootData;
    }
    if (root->getLeftChild() != nullptr) {
        root = root->getLeftChild();
        return rootData;
    }
    root = nullptr;
    return rootData;
}

#include <iostream>
#include "Tree.h"

using namespace std;


Tree::Tree() {
    this->root = nullptr;
}

Node *Tree::minNode(Node *localRoot) {
    if (localRoot->getLeftChild() == nullptr) {
        return localRoot;
    }
    return minNode(localRoot->getLeftChild());
}

Node *Tree::maxNode(Node *localRoot) {
    if (localRoot->getRightChild() == nullptr) {
        return localRoot;
    }
    return maxNode(localRoot->getRightChild());
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

/*
int Tree::pull(const int key) {
    Node *deletingNode = search(key);

    if (deletingNode == root) {
        root = deletingNode->getRightChild();
        deletingNode->getLeftChild()->setParent(deletingNode->getRightChild());
        return deletingNode->getData();
    }
    if (deletingNode->getRightChild() == nullptr && deletingNode->getLeftChild() == nullptr) {
        if (deletingNode->getParent()->getLeftChild() == deletingNode) {
            deletingNode->getParent()->setLeftChild(nullptr);
            return deletingNode->getData();
        }
        deletingNode->getParent()->setRightChild(nullptr);
        return deletingNode->getData();
    }
    if (deletingNode->getRightChild() == nullptr && deletingNode->getLeftChild() != nullptr) {
        if (deletingNode->getParent()->getLeftChild() == deletingNode) {
            deletingNode->getParent()->setLeftChild(deletingNode->getLeftChild());
            return deletingNode->getData();
        }
        deletingNode->getParent()->setRightChild(deletingNode->getLeftChild());
        return deletingNode->getData();
    }
    if (deletingNode->getRightChild() != nullptr && deletingNode->getLeftChild() == nullptr) {
        if (deletingNode->getParent()->getLeftChild() == deletingNode) {
            deletingNode->getParent()->setLeftChild(deletingNode->getRightChild());
            return deletingNode->getData();
        }
        deletingNode->getParent()->setRightChild(deletingNode->getRightChild());
        return deletingNode->getData();
    }

    // if right && left != nullptr
    if (deletingNode->getParent()->getRightChild() == deletingNode) {
        deletingNode->getParent()->setRightChild(deletingNode->getRightChild());
        return deletingNode->getData();
    } else {
        deletingNode->getParent()->setLeftChild(deletingNode->getRightChild());
    }
    deletingNode->getLeftChild()->setParent(deletingNode->getRightChild());
    return deletingNode->getData();
}
*/

/*void *Tree::pull(const int key) {
    Node *removable = search(key);

    if (removable == nullptr) {
        return nullptr;
    }
    if (removable == root) {
        root = nullptr;
        return removable->getData();
    }
    if (pullIfNoChildren(removable) ||
        pullIfNoLeftChild(removable) ||
        pullIfNoRightChild(removable) ||
        pullIfHaveChildren(removable)) {
        return removable->getData();
    }
    cout << "Something went wrong ':D" << endl;
    return nullptr;
}

bool Tree::pullIfNoChildren(Node *removable) {
    if (removable->getRightChild() == nullptr && removable->getLeftChild() == nullptr) {
        Node *parent = parentSearch(removable, root);
        if (parent->getLeftChild() == removable) {
            parent->setLeftChild(nullptr);
            return true;
        }
        parent->setRightChild(nullptr);
        return true;
    }
    return false;
}

bool Tree::pullIfNoLeftChild(Node *removable) {
    if (removable->getRightChild() != nullptr && removable->getLeftChild() == nullptr) {
        if (removable->getParent()->getLeftChild() == removable) {
            removable->getParent()->setLeftChild(removable->getRightChild());
            removable->getRightChild()->setParent(removable->getParent());
            return true;
        }
        removable->getParent()->setRightChild(removable->getRightChild());
        removable->getRightChild()->setParent(removable->getParent());
        return true;
    }
    return false;
}

bool Tree::pullIfNoRightChild(Node *removable) {
    if (removable->getRightChild() == nullptr && removable->getLeftChild() != nullptr) {
        if (removable->getParent()->getLeftChild() == removable) {
            removable->getParent()->setLeftChild(removable->getLeftChild());
            removable->getLeftChild()->setParent(removable->getParent());
            return true;
        }
        removable->getParent()->setRightChild(removable->getLeftChild());
        removable->getLeftChild()->setParent(removable->getParent());
        return true;
    }
    return false;
}

bool Tree::pullIfHaveChildren(Node *removable) {
    if (removable->getRightChild() != nullptr && removable->getLeftChild() != nullptr) {

//         search
        Node * current = removable->getRightChild();
        while (current->getLeftChild() != nullptr) {
            current = current->getRightChild();
        }
//        shift




        if (removable->getParent()->getLeftChild() == removable) {
            removable->getParent()->setLeftChild(removable->getRightChild());

            removable->getRightChild()->setParent(removable->getParent());
            removable->getLeftChild()->setParent(removable->getRightChild());
            return true;
        }
        removable->getParent()->setRightChild(removable->getLeftChild());
        removable->getLeftChild()->setParent(removable->getParent());
        return true;
    }
    return false
}*/


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

void *Tree::pull(const int key) {
    Node *parent = parentSearch(key, root);
    Node *removable = nullptr;

    if (parent == nullptr) {
        return nullptr;
    }
    if (parent->getKey() < key) {
        removable = parent->getRightChild();
    } else {
        removable = parent->getLeftChild();
    }





    if (pullIfNoChildren(removable) ||
        pullIfNoLeftChild(removable) ||
        pullIfNoRightChild(removable) ||
        pullIfHaveChildren(removable)) {
        return removable->getData();
    }
    cout << "Something went wrong ':D" << endl;
    return nullptr;
}

bool Tree::pullIfNoChildren(Node *removable, Node *parent) {
    if (removable->getRightChild() == nullptr && removable->getLeftChild() == nullptr) {
        if (parent->getLeftChild() == removable) {
            parent->setLeftChild(nullptr);
            return true;
        }
        parent->setRightChild(nullptr);
        return true;
    }
    return false;
}

bool Tree::pullIfNoLeftChild(Node *removable, Node *parent) {
    if (removable->getRightChild() != nullptr && removable->getLeftChild() == nullptr) {
        if (parent->getLeftChild() == removable) {
            parent->setLeftChild(removable->getRightChild());
            return true;
        }
        parent->setRightChild(removable->getRightChild());
        return true;
    }
    return false;
}

bool Tree::pullIfNoRightChild(Node *removable, Node *parent) {
    if (removable->getRightChild() == nullptr && removable->getLeftChild() != nullptr) {
        if (parent->getLeftChild() == removable) {
            parent->setLeftChild(removable->getLeftChild());
            return true;
        }
        parent->setRightChild(removable->getLeftChild());
        return true;
    }
    return false;
}

bool Tree::pullIfHaveChildren(Node *removable, Node *parent) {
    if (removable->getRightChild() != nullptr && removable->getLeftChild() != nullptr) {

//         search
        Node * current = removable->getRightChild();
        while (current->getLeftChild() != nullptr) {
            current = current->getRightChild();
        }
//        shift




        if (removable->getParent()->getLeftChild() == removable) {
            removable->getParent()->setLeftChild(removable->getRightChild());

            removable->getRightChild()->setParent(removable->getParent());
            removable->getLeftChild()->setParent(removable->getRightChild());
            return true;
        }
        removable->getParent()->setRightChild(removable->getLeftChild());
        removable->getLeftChild()->setParent(removable->getParent());
        return true;
    }
    return false
}

//
// Created by chern_000 on 16.03.2020.
//

#include "Tree.h"

Tree::Tree() = default;

Tree::Tree(Data *root) {
    this->root = new Node(root);
}

void Tree::push(Data *data) {
    if (root == nullptr) root = new Node(data);

    // processing will start from the root
    Node *current_node = root;

    search_and_insert(data, current_node);
}

Data *pop(int key) {
    return nullptr;
}


void Tree::for_each(void (*consumer)(Data *)) {
    if (root == nullptr) return;

    Node *current_node = root;
    process_nodes(current_node, *consumer);
}

void Tree::for_each_node(void (*consumer)(Node *)) {
    if (root == nullptr) return;

    Node *current_node = root;
    process_nodes(current_node, *consumer);
}

Node *Tree::deep_such_first(Data *data) {

    return nullptr;
}

Node *Tree::breadth(Data *data) {
    return nullptr;
}

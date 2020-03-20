#include "Binary_tree.h"

#include <utility>

Binary_tree::Binary_tree(Data *root) {
    this->root = new Node(root);
}

void Binary_tree::push(Data *data) {
    if (root == nullptr) root = new Node(data);

    // processing will start from the root
    Node *current_node = root;
}

Past_node *Binary_tree::deep_such_first(Number *data) {

//    return nullptr;
}

Past_node *Binary_tree::breadth(Number *data) {
//    return nullptr;
}

void Binary_tree::for_each(const std::function<void(Data *)>& consumer) {
    for_children(consumer, root);
}

void Binary_tree::for_children(const std::function<void(Data *)>& consumer, Node *current_node) {
    if (current_node->get_left_child() != nullptr) {
        for_children(consumer, current_node->get_left_child());
    }
    if (current_node->get_right_child() != nullptr) {
        for_children(consumer, current_node->get_right_child());
    }
    consumer(current_node->get_ptr_data());
}


Binary_tree::Node::Node(Data *data) {
    this->data = data;
    this->key = data->hash_code();
}

Data *Binary_tree::Node::get_ptr_data() {
    return data;
}

Binary_tree::Node *Binary_tree::Node::get_left_child() {
    return left_child;
}

Binary_tree::Node *Binary_tree::Node::get_right_child() {
    return right_child;
}

void Binary_tree::Node::set_data(Data *aData) {
    data = aData;
}

void Binary_tree::Node::set_left_child(Binary_tree::Node *child) {
    left_child = child;
}

void Binary_tree::Node::set_right_child(Binary_tree::Node *child) {
    right_child = child;
}

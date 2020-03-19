//
// Created by chern_000 on 16.03.2020.
//

#include "Node.h"

Node::Node(Data data) {
    this->data = &data;
    this->key = data.hashCode();
}

Data Node::get_data() {
    return *data;
}

void Node::set_data(Data aData) {
    data = &aData;
}

Node *Node::get_left_child() {
    return left_child;
}

Node *Node::get_right_child() {
    return right_child;
}

void Node::set_left_child(Node *child) {
    left_child = child;
}

void Node::set_right_child(Node *child) {
    right_child = child;
}
//
// Created by chern_000 on 16.03.2020.
//

#include "Past_node.h"

Past_node::Past_node(Number data) {
    this->data = &data;
    this->key = data.hashCode();
}

Number Past_node::get_data() {
    return *data;
}

void Past_node::set_data(Number aData) {
    data = &aData;
}

Past_node *Past_node::get_left_child() {
    return left_child;
}

Past_node *Past_node::get_right_child() {
    return right_child;
}

void Past_node::set_left_child(Past_node *child) {
    left_child = child;
}

void Past_node::set_right_child(Past_node *child) {
    right_child = child;
}
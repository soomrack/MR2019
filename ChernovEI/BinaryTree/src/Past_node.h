//
// Created by chern_000 on 16.03.2020.
//

#ifndef BINARYTREEV2_PAST_NODE_H
#define BINARYTREEV2_PAST_NODE_H


#include "entities/Number.h"

class Past_node {
private:
    int key;
    Number *data;
    Past_node *left_child = nullptr;
    Past_node *right_child = nullptr;

public:
    Past_node(Number data);

    Number get_data();

    void set_data(Number aData);

private:    //  TODO: delete pointers?
    Past_node *get_left_child();

    Past_node *get_right_child();

    void set_left_child(Past_node *child);

    void set_right_child(Past_node *child);
};


#endif //BINARYTREEV2_PAST_NODE_H

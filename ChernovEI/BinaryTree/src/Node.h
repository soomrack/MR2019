//
// Created by chern_000 on 16.03.2020.
//

#ifndef BINARYTREEV2_NODE_H
#define BINARYTREEV2_NODE_H


#include "../tests/Data.h"

class Node {
private:
    int key;
    Data *data;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

public:
    Node(Data data);

    Data get_data();

    void set_data(Data aData);

private:    //  TODO: delete pointers?
    Node *get_left_child();

    Node *get_right_child();

    void set_left_child(Node *child);

    void set_right_child(Node *child);
};


#endif //BINARYTREEV2_NODE_H

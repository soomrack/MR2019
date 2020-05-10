#ifndef BINARYTREEV2_BINARY_TREE_H
#define BINARYTREEV2_BINARY_TREE_H


#include "Past_node.h"
#include "entities/Data.h"
#include <functional>

/**
 * This class describes the data structure binary tree.
 * This implementation only works with Data types.
 *
 * @version 3.0
 * */
class Binary_tree {
private:
    class Node;

    Node *root;

public:
    explicit Binary_tree(Data *root);

    /**
     * This method applies the consumer function to each node in the tree.
     * */
    void for_each(const std::function<void(Data *)>& consumer);

    /**
     * Adds to the tree the child node or the root node.
     * If the node is to left of the parent it is >= to parent.
     * If the node is to right of the parent it < to parent.
     * */
    void push(Data *data);

    /**
     * Removes first node containing specified key
     *
     * @return nullptr if key is unfounded
     * */
//    Number *pop(int key);

private:
    static void for_children(const std::function<void(Data *)>& consumer, Node *current_node);

    class Node {
    private:
        int key;
        Data *data;
        Node *left_child = nullptr;
        Node *right_child = nullptr;

    public:
        Node(Data *data);

        Data *get_ptr_data();

        Node *get_left_child();

        Node *get_right_child();

        void set_data(Data *aData);

        void set_left_child(Node *child);

        void set_right_child(Node *child);
    };
};


#endif //BINARYTREEV2_BINARY_TREE_H

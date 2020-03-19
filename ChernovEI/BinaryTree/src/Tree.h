//
// Created by chern_000 on 16.03.2020.
//

#ifndef BINARYTREEV2_TREE_H
#define BINARYTREEV2_TREE_H


#include "Node.h"
#include "../tests/Data.h"

class Tree {
private:
    Node *root = nullptr;

public:
    Tree();

    explicit Tree(Data *root);

    /**
     * Adds to the tree the node or the root.
     * If the node is to left of the parent it is >= to parent.
     * If the node is to right of the parent it < to parent.
     * */
    void push(Data *data);

    /**
     * Removes first node containing specified key
     *
     * @return nullptr if key is unfounded
     * */
    Data *pop(int key);

    void for_each(void (*consumer)(Data *));

private:
    void for_each_node(void (*consumer)(Node *));

    /**
     * Processes the passed node and all its children
     * */
    static void process_nodes(Node *current_node, void (*consumer)(Data *)) {
        if (current_node->get_left_child() != nullptr) {
            process_nodes(current_node->get_left_child(), *consumer);
        }
        if (current_node->get_right_child() != nullptr) {
            process_nodes(current_node->get_right_child(), *consumer);
        }
        consumer(current_node->get_data());
    }

    /**
     *
     *
     * @param the desired tree element
     * */
    Node *deep_such_first(Data *data);

    Node *breadth(Data *data);

    static void search_and_insert(Data *data, Node *current_node) {
        if (current_node->get_data().compareTo(*data) > 0) {
            if (insert_to_right(data, current_node) == nullptr) {
                return;
            }

            search_and_insert(data, current_node);
        }
        // Current node <= data
        if (insert_to_left(data, current_node) == nullptr) {
            return;
        }

        search_and_insert(data, current_node);
    }

    static Node *insert_to_left(Data *data, Node *current_node) {
        if (current_node->get_left_child() == nullptr) {
            current_node->set_left_child(new Node(data));
            return nullptr;
        }
        return current_node->get_left_child();
    }

    static Node *insert_to_right(Data *data, Node *current_node) {
        if (current_node->get_right_child() == nullptr) {
            current_node->set_right_child(new Node(data));
            return nullptr;
        }
        return current_node->get_right_child();
    }
};


#endif //BINARYTREEV2_TREE_H

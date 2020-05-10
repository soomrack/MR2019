#ifndef BINARYTREEV2_TREE_TEST_H
#define BINARYTREEV2_TREE_TEST_H


#include "../../src/Binary_tree.h"
#include "Main_test.h"

class Tree_test : public Main_test {
private:
    Binary_tree *tree;

public:
    /**
     * Creates new test with a fully filled three-level binary tree (default tree).
     * Uses Tree.push().
     * 5
     * 2_8
     * 1_3_7_9
     * */
    Tree_test();

    explicit Tree_test(Binary_tree *tree);

    /**
     * Calls all tests of the class and subclasses.
     * Subject to overriding.
     * */
    void test_all() override;

    void test_push();

    /**
     * Creates the default tree and tests count containing Number's and its values.
     * */
    static void test_for_each();

private:
    static int get_nodes_count(Binary_tree *tree);

    static void test_tree_nodes_values(Binary_tree *tree);
};


#endif //BINARYTREEV2_TREE_TEST_H

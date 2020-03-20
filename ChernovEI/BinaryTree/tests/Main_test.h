#ifndef BINARYTREEV2_MAIN_TEST_H
#define BINARYTREEV2_MAIN_TEST_H


#include "../src/Binary_tree.h"

#include <stdexcept>


class Main_test {
private:
    Binary_tree *tree;

public:
    /**
     * Creates new test with a fully filled three-level binary tree (the default tree)
     * containing keys 0-6.
     * Uses Tree.push().
     * 3
     * 1_5
     * 0_2_4_6
     * */
    Main_test();

    explicit Main_test(Binary_tree *tree);

    /**
     * @return Binary_tree pointer:
     * 3
     * 1_5
     * 0_2_4_6
     * */
    static Binary_tree *get_default_tree();

    /**
     * Tests all subclasses for passed tree.
     * Subject to overriding.
     * */
    virtual void test_all();
};


#endif //BINARYTREEV2_MAIN_TEST_H

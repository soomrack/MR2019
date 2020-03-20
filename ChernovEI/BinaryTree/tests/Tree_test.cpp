/*
 * Source files related to the Tree_test.h:
 * Tree_test.cpp
 * test_for_each.cpp
 * */
#include "Tree_test.h"

Tree_test::Tree_test() {
    this->tree = get_default_tree();
}

Tree_test::Tree_test(Binary_tree *tree) : Main_test(tree) {
    //    TODO: #null_argument
    if (tree == nullptr) {
        throw std::invalid_argument("The argument passed cannot be nullptr!");
    }

    this->tree = tree;
}

void Tree_test::test_all() {
    //  TODO
    test_push();
    test_for_each();
}

void Tree_test::test_push() {
    for (int pushed_num = 0; pushed_num < 10; pushed_num++) {
        tree->push(new Number(pushed_num));
    }
}



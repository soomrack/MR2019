#include "Main_test.h"
#include "Tree_test.h"
#include <stdexcept>

Main_test::Main_test() {
    this->tree = get_default_tree();
}

Main_test::Main_test(Binary_tree *tree) {
//    TODO: #null_argument
    if (tree == nullptr) {
        throw std::invalid_argument("The argument passed cannot be nullptr!");
    }

    this->tree = tree;
}

Binary_tree *Main_test::get_default_tree() {
    auto default_tree = new Binary_tree(new Number(5));
    default_tree->push(new Number(2));
    default_tree->push(new Number(8));
    default_tree->push(new Number(1));
    default_tree->push(new Number(3));
    default_tree->push(new Number(7));
    default_tree->push(new Number(9));
    return default_tree;
}

void Main_test::test_all() {
    (new Tree_test(tree))->test_all();
}

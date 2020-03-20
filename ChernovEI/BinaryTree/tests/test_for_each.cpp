#include "Tree_test.h"

void Tree_test::test_for_each() {
    Binary_tree *default_tree = get_default_tree();


}

class Number_tree_counter {
public:
    static int counter;

    static void increment(Data * data) {
        (void) data;
        counter++;
    }

    static void zeroing() {
        counter = 0;
    }
};

int Tree_test::get_nodes_count(Binary_tree *tree) {
    Number_tree_counter::zeroing();
    tree->for_each(Number_tree_counter::increment);
    return Number_tree_counter::counter;
}

#include "Tree_test.h"

void Tree_test::test_for_each() {
    Binary_tree *default_tree = get_default_tree();

    assert(get_nodes_count(default_tree) == 7);

}


class Number_tree_counter {
public:
    static int counter;

    /*
     * @param data added for passing the increment function to Tree.for_each()
     * */
    static void increment(Data *data) {
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


static std::vector<int> tree_nodes_values(7);

void fill_tree_nodes_values_vector() {
    for (int i = 0; i < 7; i++) {
        tree_nodes_values.push_back(i);
    }
}

void test_single_tree_node_value(Data *number) {
    // TODO: current
    //  TODO: dynamic_cast
    for (std::vector<int>::iterator iter = tree_nodes_values.begin();
         iter != tree_nodes_values.end(); iter++) {
        if (tree_nodes_values[iter] == dynamic_cast<Number*>(number)->get())
    }
}

void Tree_test::test_tree_nodes_values(Binary_tree *tree) {
    fill_tree_nodes_values_vector();
    tree->for_each()
}




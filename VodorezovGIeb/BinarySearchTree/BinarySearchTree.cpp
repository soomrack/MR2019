#include <iostream>
#include <queue> 

#include"treeMethods.h"

using namespace std;

int main() 
{
    Tree myTree;

    myTree.add_node(20, 0);
    myTree.add_node(10, 0);
    myTree.add_node(30, 0);
    myTree.add_node(5, 0);
    myTree.add_node(15, 0);
    myTree.add_node(7, 0);
    myTree.add_node(25, 0);
    myTree.add_node(12, 0);
    myTree.add_node(35, 0);
    myTree.add_node(17, 0);

    //cout << '\n';

    //myTree.print_tree_dsf(myTree.root);
    myTree.print_tree_bsf(myTree.root);

    myTree.delete_node(myTree.root, 12);
    myTree.delete_node(myTree.root, 10);
   // myTree.delete_node(myTree.root, 30);
    cout << '\n';
    cout << '\n';
    //cout << myTree.search_parent_of_node(myTree.root, 5)->key;

    myTree.print_tree_bsf(myTree.root);

}


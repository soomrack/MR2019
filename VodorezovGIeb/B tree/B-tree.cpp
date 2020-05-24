//На данный момент реализованно только добавление элеиентов и вывод дерево в консоль
//Доделать: удаление элементов и создать пару key - data

#include"treeMethods.h"
#include <iostream>

using namespace std;

int main()
{
    Tree b_tree;

    b_tree.add_element(1);
    b_tree.add_element(20);
    b_tree.add_element(10);
    b_tree.add_element(40);
    b_tree.add_element(60);
    b_tree.add_element(50);
    b_tree.add_element(25);
    b_tree.add_element(30);
    b_tree.add_element(35);
    b_tree.add_element(70);
    b_tree.add_element(80);

    b_tree.print_tree(b_tree.root);

}

//
// Created by chern_000 on 16.03.2020.
//

#include "Test.h"

/**
 * 5
 * 3_9
 * 1_4_7_-
 * -_2_6_8_-_-
 * */
Test::Test() {
    tree = new Tree(new Data(5));
    tree->push(new Data(3));
    tree->push(new Data(1));
    tree->push(new Data(2));
    tree->push(new Data(4));
    tree->push(new Data(9));
    tree->push(new Data(7));
    tree->push(new Data(8));
    tree->push(new Data(6));
}

/**
 * Don't throws exception
 * if a left child is <= to testing node
 * & a right child is > to testing node.
 * */
void Test::test_push() {

}

cmake_minimum_required(VERSION 3.14)
project(BinaryTreeV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinaryTreeV2 main.cpp
        src/Past_node src/Binary_tree src/Data
        tests/Number tests/Main_test tests/Tree_test tests/test_for_each.cpp)
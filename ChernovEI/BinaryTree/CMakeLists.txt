cmake_minimum_required(VERSION 3.14)
project(BinaryTreeV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinaryTreeV2 main.cpp src/Node src/Tree tests/Data tests/Test)
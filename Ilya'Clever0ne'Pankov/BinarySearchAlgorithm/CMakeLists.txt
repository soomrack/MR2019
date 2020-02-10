cmake_minimum_required(VERSION 3.15)
project(BinarySearchAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinarySearchAlgorithm test.cpp)
add_library(BinarySearch binary_search)
target_link_libraries(BinarySearchAlgorithm BinarySearch)
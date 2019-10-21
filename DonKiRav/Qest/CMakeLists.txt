
cmake_minimum_required(VERSION 3.15)
project(untitled5 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled5 main.c)
add_library(MyLibr MyLibr)
target_link_libraries(untitled5 MyLibr)
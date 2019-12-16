cmake_minimum_required(VERSION 3.15)
project(Lab4Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4Test tests)
add_library(functions functions)
target_link_libraries(Lab4Test functions)
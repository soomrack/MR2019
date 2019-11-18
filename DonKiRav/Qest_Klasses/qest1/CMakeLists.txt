cmake_minimum_required(VERSION 3.15)
project(untitled18)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled18 main.cpp)
add_library(QestLib QestLib)
add_library(Test_Chern ../../../ChernovEI/RandomTest.h)
target_link_libraries(untitled18 QestLib Test_Chern)
cmake_minimum_required(VERSION 3.14)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp)

add_library(RandomTest STATIC RandomTest.h RandomTest.cpp)
target_link_libraries(untitled2 RandomTest)

#add_library(RandomTest STATIC
#        /home/ageent/CLionProjects/MR2019/ChernovEI/RandomTest.h
#        /home/ageent/CLionProjects/MR2019/ChernovEI/RandomTest.cpp)
cmake_minimum_required(VERSION 3.15)
project(TestTaskWithClasses)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestTaskWithClasses main.cpp)
add_library(questions questions)
target_link_libraries(TestTaskWithClasses questions)
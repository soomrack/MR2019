cmake_minimum_required(VERSION 3.15)
project(QUEST)

set(CMAKE_CXX_STANDARD 14)

add_executable(QUEST main.cpp)
add_library(API api)
add_library(CPP_QUEST cpp_quest)
add_library(CLEVER0NE_QUEST clever0ne_quest)
target_link_libraries(QUEST API)
target_link_libraries(QUEST CPP_QUEST)
target_link_libraries(QUEST CLEVER0NE_QUEST)

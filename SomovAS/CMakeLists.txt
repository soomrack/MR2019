cmake_minimum_required(VERSION 3.15)
project(SomovAS)

set(CMAKE_CXX_STANDARD 14)

add_executable(SomovAS main test api.h api.cpp try.h)
add_library(mylib ../YakimenkoGK/LibExp_Yakimenko/sumator)
target_link_libraries(SomovAS mylib)

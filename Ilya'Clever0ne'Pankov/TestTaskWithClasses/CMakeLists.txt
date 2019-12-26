
project(TestTaskWithClasses)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestTaskWithClasses main.cpp)
add_library(questions questions)
add_library(mylib mylib)
add_library(lib1 "../../SOKOLOV-D-A/CMake_Quiz-with-lib/CMake_Test/CMake_Test_library")
target_link_libraries(TestTaskWithClasses questions mylib lib1)
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMake_Test")

set (CMAKE_CXX_STANDARD 11)

# Include sub-projects.
add_subdirectory ("CMake_Test")

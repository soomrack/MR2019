# CMakeList.txt : CMake project for Testik_by_teacher, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Testik_by_teacher main)
add_library(api api)
add_library(quest cpp_quest)
target_link_libraries(Testik_by_teacher api )
target_link_libraries(Testik_by_teacher quest )

# TODO: Add tests and install targets if needed.

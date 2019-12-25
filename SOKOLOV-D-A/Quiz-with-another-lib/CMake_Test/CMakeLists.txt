# CMakeList.txt : CMake project for CMake_Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMake_Test main.cpp)
add_library (CMake_Test_library CMake_Test_library )
add_library (pankov "../library/questions")
add_library (yasha "../library/QestLib")
TARGET_LINK_LIBRARIES(CMake_Test CMake_Test_library)
TARGET_LINK_LIBRARIES(CMake_Test pankov)
TARGET_LINK_LIBRARIES(CMake_Test yasha)
# TODO: Add tests and install targets if needed.

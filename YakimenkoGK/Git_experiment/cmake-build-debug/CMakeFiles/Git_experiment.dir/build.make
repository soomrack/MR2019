# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Git_experiment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Git_experiment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Git_experiment.dir/flags.make

CMakeFiles/Git_experiment.dir/main.cpp.obj: CMakeFiles/Git_experiment.dir/flags.make
CMakeFiles/Git_experiment.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Git_experiment.dir/main.cpp.obj"
	C:\Users\nne_l\.CLion2019.2\Min\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Git_experiment.dir\main.cpp.obj -c C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\main.cpp

CMakeFiles/Git_experiment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Git_experiment.dir/main.cpp.i"
	C:\Users\nne_l\.CLion2019.2\Min\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\main.cpp > CMakeFiles\Git_experiment.dir\main.cpp.i

CMakeFiles/Git_experiment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Git_experiment.dir/main.cpp.s"
	C:\Users\nne_l\.CLion2019.2\Min\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\main.cpp -o CMakeFiles\Git_experiment.dir\main.cpp.s

# Object files for target Git_experiment
Git_experiment_OBJECTS = \
"CMakeFiles/Git_experiment.dir/main.cpp.obj"

# External object files for target Git_experiment
Git_experiment_EXTERNAL_OBJECTS =

Git_experiment.exe: CMakeFiles/Git_experiment.dir/main.cpp.obj
Git_experiment.exe: CMakeFiles/Git_experiment.dir/build.make
Git_experiment.exe: CMakeFiles/Git_experiment.dir/linklibs.rsp
Git_experiment.exe: CMakeFiles/Git_experiment.dir/objects1.rsp
Git_experiment.exe: CMakeFiles/Git_experiment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Git_experiment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Git_experiment.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Git_experiment.dir/build: Git_experiment.exe

.PHONY : CMakeFiles/Git_experiment.dir/build

CMakeFiles/Git_experiment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Git_experiment.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Git_experiment.dir/clean

CMakeFiles/Git_experiment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug C:\Users\nne_l\CLionProjects\MR2019\YakimenkoGK\Git_experiment\cmake-build-debug\CMakeFiles\Git_experiment.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Git_experiment.dir/depend


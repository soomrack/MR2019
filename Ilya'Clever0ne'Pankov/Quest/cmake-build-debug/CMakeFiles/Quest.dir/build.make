# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/QUEST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QUEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QUEST.dir/flags.make

CMakeFiles/QUEST.dir/main.cpp.obj: CMakeFiles/QUEST.dir/flags.make
CMakeFiles/QUEST.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QUEST.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\QUEST.dir\main.cpp.obj -c "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\main.cpp"

CMakeFiles/QUEST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QUEST.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\main.cpp" > CMakeFiles\QUEST.dir\main.cpp.i

CMakeFiles/QUEST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QUEST.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\main.cpp" -o CMakeFiles\QUEST.dir\main.cpp.s

# Object files for target QUEST
QUEST_OBJECTS = \
"CMakeFiles/QUEST.dir/main.cpp.obj"

# External object files for target QUEST
QUEST_EXTERNAL_OBJECTS =

QUEST.exe: CMakeFiles/QUEST.dir/main.cpp.obj
QUEST.exe: CMakeFiles/QUEST.dir/build.make
QUEST.exe: libAPI.a
QUEST.exe: libCPP_QUEST.a
QUEST.exe: libCLEVER0NE_QUEST.a
QUEST.exe: CMakeFiles/QUEST.dir/linklibs.rsp
QUEST.exe: CMakeFiles/QUEST.dir/objects1.rsp
QUEST.exe: CMakeFiles/QUEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable QUEST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\QUEST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QUEST.dir/build: QUEST.exe

.PHONY : CMakeFiles/QUEST.dir/build

CMakeFiles/QUEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QUEST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QUEST.dir/clean

CMakeFiles/QUEST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest" "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest" "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug" "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug" "D:\For Administrator\GitHub\MR2019\Ilya'Clever0ne'Pankov\Quest\cmake-build-debug\CMakeFiles\Quest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/QUEST.dir/depend

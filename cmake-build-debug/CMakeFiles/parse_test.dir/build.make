# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = C:\Users\eeydem\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.4892.24\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\eeydem\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.4892.24\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Documents\Work\ECE_LAB\parse_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parse_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parse_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parse_test.dir/flags.make

CMakeFiles/parse_test.dir/src/main.cpp.obj: CMakeFiles/parse_test.dir/flags.make
CMakeFiles/parse_test.dir/src/main.cpp.obj: CMakeFiles/parse_test.dir/includes_CXX.rsp
CMakeFiles/parse_test.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parse_test.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\parse_test.dir\src\main.cpp.obj -c E:\Documents\Work\ECE_LAB\parse_test\src\main.cpp

CMakeFiles/parse_test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parse_test.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Documents\Work\ECE_LAB\parse_test\src\main.cpp > CMakeFiles\parse_test.dir\src\main.cpp.i

CMakeFiles/parse_test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parse_test.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Documents\Work\ECE_LAB\parse_test\src\main.cpp -o CMakeFiles\parse_test.dir\src\main.cpp.s

# Object files for target parse_test
parse_test_OBJECTS = \
"CMakeFiles/parse_test.dir/src/main.cpp.obj"

# External object files for target parse_test
parse_test_EXTERNAL_OBJECTS =

parse_test.exe: CMakeFiles/parse_test.dir/src/main.cpp.obj
parse_test.exe: CMakeFiles/parse_test.dir/build.make
parse_test.exe: CMakeFiles/parse_test.dir/linklibs.rsp
parse_test.exe: CMakeFiles/parse_test.dir/objects1.rsp
parse_test.exe: CMakeFiles/parse_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parse_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\parse_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parse_test.dir/build: parse_test.exe

.PHONY : CMakeFiles/parse_test.dir/build

CMakeFiles/parse_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\parse_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/parse_test.dir/clean

CMakeFiles/parse_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Documents\Work\ECE_LAB\parse_test E:\Documents\Work\ECE_LAB\parse_test E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug E:\Documents\Work\ECE_LAB\parse_test\cmake-build-debug\CMakeFiles\parse_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parse_test.dir/depend

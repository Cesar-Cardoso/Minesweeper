# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cesar/Desktop/git/Minesweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cesar/Desktop/git/Minesweeper/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project3.dir/flags.make

CMakeFiles/Project3.dir/Main.cpp.o: CMakeFiles/Project3.dir/flags.make
CMakeFiles/Project3.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/Desktop/git/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project3.dir/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project3.dir/Main.cpp.o -c /home/cesar/Desktop/git/Minesweeper/Main.cpp

CMakeFiles/Project3.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project3.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cesar/Desktop/git/Minesweeper/Main.cpp > CMakeFiles/Project3.dir/Main.cpp.i

CMakeFiles/Project3.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project3.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cesar/Desktop/git/Minesweeper/Main.cpp -o CMakeFiles/Project3.dir/Main.cpp.s

CMakeFiles/Project3.dir/Tile.cpp.o: CMakeFiles/Project3.dir/flags.make
CMakeFiles/Project3.dir/Tile.cpp.o: ../Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/Desktop/git/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project3.dir/Tile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project3.dir/Tile.cpp.o -c /home/cesar/Desktop/git/Minesweeper/Tile.cpp

CMakeFiles/Project3.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project3.dir/Tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cesar/Desktop/git/Minesweeper/Tile.cpp > CMakeFiles/Project3.dir/Tile.cpp.i

CMakeFiles/Project3.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project3.dir/Tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cesar/Desktop/git/Minesweeper/Tile.cpp -o CMakeFiles/Project3.dir/Tile.cpp.s

CMakeFiles/Project3.dir/Game.cpp.o: CMakeFiles/Project3.dir/flags.make
CMakeFiles/Project3.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/Desktop/git/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project3.dir/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project3.dir/Game.cpp.o -c /home/cesar/Desktop/git/Minesweeper/Game.cpp

CMakeFiles/Project3.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project3.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cesar/Desktop/git/Minesweeper/Game.cpp > CMakeFiles/Project3.dir/Game.cpp.i

CMakeFiles/Project3.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project3.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cesar/Desktop/git/Minesweeper/Game.cpp -o CMakeFiles/Project3.dir/Game.cpp.s

# Object files for target Project3
Project3_OBJECTS = \
"CMakeFiles/Project3.dir/Main.cpp.o" \
"CMakeFiles/Project3.dir/Tile.cpp.o" \
"CMakeFiles/Project3.dir/Game.cpp.o"

# External object files for target Project3
Project3_EXTERNAL_OBJECTS =

Project3: CMakeFiles/Project3.dir/Main.cpp.o
Project3: CMakeFiles/Project3.dir/Tile.cpp.o
Project3: CMakeFiles/Project3.dir/Game.cpp.o
Project3: CMakeFiles/Project3.dir/build.make
Project3: CMakeFiles/Project3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cesar/Desktop/git/Minesweeper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Project3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project3.dir/build: Project3

.PHONY : CMakeFiles/Project3.dir/build

CMakeFiles/Project3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project3.dir/clean

CMakeFiles/Project3.dir/depend:
	cd /home/cesar/Desktop/git/Minesweeper/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cesar/Desktop/git/Minesweeper /home/cesar/Desktop/git/Minesweeper /home/cesar/Desktop/git/Minesweeper/cmake-build-debug /home/cesar/Desktop/git/Minesweeper/cmake-build-debug /home/cesar/Desktop/git/Minesweeper/cmake-build-debug/CMakeFiles/Project3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project3.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/main.cpp.o -MF CMakeFiles/game.dir/src/main.cpp.o.d -o CMakeFiles/game.dir/src/main.cpp.o -c /app/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

CMakeFiles/game.dir/src/Game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Game.cpp.o: ../src/Game.cpp
CMakeFiles/game.dir/src/Game.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/Game.cpp.o -MF CMakeFiles/game.dir/src/Game.cpp.o.d -o CMakeFiles/game.dir/src/Game.cpp.o -c /app/src/Game.cpp

CMakeFiles/game.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/Game.cpp > CMakeFiles/game.dir/src/Game.cpp.i

CMakeFiles/game.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/Game.cpp -o CMakeFiles/game.dir/src/Game.cpp.s

CMakeFiles/game.dir/src/TextureManager.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/TextureManager.cpp.o: ../src/TextureManager.cpp
CMakeFiles/game.dir/src/TextureManager.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/TextureManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/TextureManager.cpp.o -MF CMakeFiles/game.dir/src/TextureManager.cpp.o.d -o CMakeFiles/game.dir/src/TextureManager.cpp.o -c /app/src/TextureManager.cpp

CMakeFiles/game.dir/src/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/TextureManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/TextureManager.cpp > CMakeFiles/game.dir/src/TextureManager.cpp.i

CMakeFiles/game.dir/src/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/TextureManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/TextureManager.cpp -o CMakeFiles/game.dir/src/TextureManager.cpp.s

CMakeFiles/game.dir/src/GameObject.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/GameObject.cpp.o: ../src/GameObject.cpp
CMakeFiles/game.dir/src/GameObject.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/GameObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/GameObject.cpp.o -MF CMakeFiles/game.dir/src/GameObject.cpp.o.d -o CMakeFiles/game.dir/src/GameObject.cpp.o -c /app/src/GameObject.cpp

CMakeFiles/game.dir/src/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/GameObject.cpp > CMakeFiles/game.dir/src/GameObject.cpp.i

CMakeFiles/game.dir/src/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/GameObject.cpp -o CMakeFiles/game.dir/src/GameObject.cpp.s

CMakeFiles/game.dir/src/Map.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Map.cpp.o: ../src/Map.cpp
CMakeFiles/game.dir/src/Map.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/Map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/Map.cpp.o -MF CMakeFiles/game.dir/src/Map.cpp.o.d -o CMakeFiles/game.dir/src/Map.cpp.o -c /app/src/Map.cpp

CMakeFiles/game.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/Map.cpp > CMakeFiles/game.dir/src/Map.cpp.i

CMakeFiles/game.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/Map.cpp -o CMakeFiles/game.dir/src/Map.cpp.s

CMakeFiles/game.dir/src/astar.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/astar.cpp.o: ../src/astar.cpp
CMakeFiles/game.dir/src/astar.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/astar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/astar.cpp.o -MF CMakeFiles/game.dir/src/astar.cpp.o.d -o CMakeFiles/game.dir/src/astar.cpp.o -c /app/src/astar.cpp

CMakeFiles/game.dir/src/astar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/astar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/astar.cpp > CMakeFiles/game.dir/src/astar.cpp.i

CMakeFiles/game.dir/src/astar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/astar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/astar.cpp -o CMakeFiles/game.dir/src/astar.cpp.s

CMakeFiles/game.dir/src/Node.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Node.cpp.o: ../src/Node.cpp
CMakeFiles/game.dir/src/Node.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/Node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/Node.cpp.o -MF CMakeFiles/game.dir/src/Node.cpp.o.d -o CMakeFiles/game.dir/src/Node.cpp.o -c /app/src/Node.cpp

CMakeFiles/game.dir/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/Node.cpp > CMakeFiles/game.dir/src/Node.cpp.i

CMakeFiles/game.dir/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/Node.cpp -o CMakeFiles/game.dir/src/Node.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/main.cpp.o" \
"CMakeFiles/game.dir/src/Game.cpp.o" \
"CMakeFiles/game.dir/src/TextureManager.cpp.o" \
"CMakeFiles/game.dir/src/GameObject.cpp.o" \
"CMakeFiles/game.dir/src/Map.cpp.o" \
"CMakeFiles/game.dir/src/astar.cpp.o" \
"CMakeFiles/game.dir/src/Node.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/src/Game.cpp.o
game: CMakeFiles/game.dir/src/TextureManager.cpp.o
game: CMakeFiles/game.dir/src/GameObject.cpp.o
game: CMakeFiles/game.dir/src/Map.cpp.o
game: CMakeFiles/game.dir/src/astar.cpp.o
game: CMakeFiles/game.dir/src/Node.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app /app /app/build /app/build /app/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend


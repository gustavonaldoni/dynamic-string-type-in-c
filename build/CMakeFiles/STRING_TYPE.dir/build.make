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
CMAKE_SOURCE_DIR = /home/gustavo/dynamic-string-type-in-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gustavo/dynamic-string-type-in-c/build

# Include any dependencies generated for this target.
include CMakeFiles/STRING_TYPE.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/STRING_TYPE.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/STRING_TYPE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STRING_TYPE.dir/flags.make

CMakeFiles/STRING_TYPE.dir/src/main.c.o: CMakeFiles/STRING_TYPE.dir/flags.make
CMakeFiles/STRING_TYPE.dir/src/main.c.o: ../src/main.c
CMakeFiles/STRING_TYPE.dir/src/main.c.o: CMakeFiles/STRING_TYPE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/dynamic-string-type-in-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/STRING_TYPE.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/STRING_TYPE.dir/src/main.c.o -MF CMakeFiles/STRING_TYPE.dir/src/main.c.o.d -o CMakeFiles/STRING_TYPE.dir/src/main.c.o -c /home/gustavo/dynamic-string-type-in-c/src/main.c

CMakeFiles/STRING_TYPE.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/STRING_TYPE.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gustavo/dynamic-string-type-in-c/src/main.c > CMakeFiles/STRING_TYPE.dir/src/main.c.i

CMakeFiles/STRING_TYPE.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/STRING_TYPE.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gustavo/dynamic-string-type-in-c/src/main.c -o CMakeFiles/STRING_TYPE.dir/src/main.c.s

# Object files for target STRING_TYPE
STRING_TYPE_OBJECTS = \
"CMakeFiles/STRING_TYPE.dir/src/main.c.o"

# External object files for target STRING_TYPE
STRING_TYPE_EXTERNAL_OBJECTS =

STRING_TYPE: CMakeFiles/STRING_TYPE.dir/src/main.c.o
STRING_TYPE: CMakeFiles/STRING_TYPE.dir/build.make
STRING_TYPE: string_type/libstring_type.a
STRING_TYPE: CMakeFiles/STRING_TYPE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gustavo/dynamic-string-type-in-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable STRING_TYPE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STRING_TYPE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STRING_TYPE.dir/build: STRING_TYPE
.PHONY : CMakeFiles/STRING_TYPE.dir/build

CMakeFiles/STRING_TYPE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/STRING_TYPE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/STRING_TYPE.dir/clean

CMakeFiles/STRING_TYPE.dir/depend:
	cd /home/gustavo/dynamic-string-type-in-c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gustavo/dynamic-string-type-in-c /home/gustavo/dynamic-string-type-in-c /home/gustavo/dynamic-string-type-in-c/build /home/gustavo/dynamic-string-type-in-c/build /home/gustavo/dynamic-string-type-in-c/build/CMakeFiles/STRING_TYPE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STRING_TYPE.dir/depend


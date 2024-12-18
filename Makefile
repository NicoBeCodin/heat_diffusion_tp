# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/nico/TP-CHPS/oop_td/heat_equation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nico/TP-CHPS/oop_td/heat_equation

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nico/TP-CHPS/oop_td/heat_equation/CMakeFiles /home/nico/TP-CHPS/oop_td/heat_equation//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nico/TP-CHPS/oop_td/heat_equation/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named simulation

# Build rule for target.
simulation: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 simulation
.PHONY : simulation

# fast build rule for target.
simulation/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/build
.PHONY : simulation/fast

Equation.o: Equation.cpp.o
.PHONY : Equation.o

# target to build an object file
Equation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Equation.cpp.o
.PHONY : Equation.cpp.o

Equation.i: Equation.cpp.i
.PHONY : Equation.i

# target to preprocess a source file
Equation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Equation.cpp.i
.PHONY : Equation.cpp.i

Equation.s: Equation.cpp.s
.PHONY : Equation.s

# target to generate assembly for a file
Equation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Equation.cpp.s
.PHONY : Equation.cpp.s

GaussSeidel.o: GaussSeidel.cpp.o
.PHONY : GaussSeidel.o

# target to build an object file
GaussSeidel.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/GaussSeidel.cpp.o
.PHONY : GaussSeidel.cpp.o

GaussSeidel.i: GaussSeidel.cpp.i
.PHONY : GaussSeidel.i

# target to preprocess a source file
GaussSeidel.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/GaussSeidel.cpp.i
.PHONY : GaussSeidel.cpp.i

GaussSeidel.s: GaussSeidel.cpp.s
.PHONY : GaussSeidel.s

# target to generate assembly for a file
GaussSeidel.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/GaussSeidel.cpp.s
.PHONY : GaussSeidel.cpp.s

Jacobi.o: Jacobi.cpp.o
.PHONY : Jacobi.o

# target to build an object file
Jacobi.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Jacobi.cpp.o
.PHONY : Jacobi.cpp.o

Jacobi.i: Jacobi.cpp.i
.PHONY : Jacobi.i

# target to preprocess a source file
Jacobi.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Jacobi.cpp.i
.PHONY : Jacobi.cpp.i

Jacobi.s: Jacobi.cpp.s
.PHONY : Jacobi.s

# target to generate assembly for a file
Jacobi.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Jacobi.cpp.s
.PHONY : Jacobi.cpp.s

Problem.o: Problem.cpp.o
.PHONY : Problem.o

# target to build an object file
Problem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Problem.cpp.o
.PHONY : Problem.cpp.o

Problem.i: Problem.cpp.i
.PHONY : Problem.i

# target to preprocess a source file
Problem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Problem.cpp.i
.PHONY : Problem.cpp.i

Problem.s: Problem.cpp.s
.PHONY : Problem.s

# target to generate assembly for a file
Problem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Problem.cpp.s
.PHONY : Problem.cpp.s

Timer.o: Timer.cpp.o
.PHONY : Timer.o

# target to build an object file
Timer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Timer.cpp.o
.PHONY : Timer.cpp.o

Timer.i: Timer.cpp.i
.PHONY : Timer.i

# target to preprocess a source file
Timer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Timer.cpp.i
.PHONY : Timer.cpp.i

Timer.s: Timer.cpp.s
.PHONY : Timer.s

# target to generate assembly for a file
Timer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Timer.cpp.s
.PHONY : Timer.cpp.s

UniformMesh.o: UniformMesh.cpp.o
.PHONY : UniformMesh.o

# target to build an object file
UniformMesh.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/UniformMesh.cpp.o
.PHONY : UniformMesh.cpp.o

UniformMesh.i: UniformMesh.cpp.i
.PHONY : UniformMesh.i

# target to preprocess a source file
UniformMesh.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/UniformMesh.cpp.i
.PHONY : UniformMesh.cpp.i

UniformMesh.s: UniformMesh.cpp.s
.PHONY : UniformMesh.s

# target to generate assembly for a file
UniformMesh.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/UniformMesh.cpp.s
.PHONY : UniformMesh.cpp.s

Variable.o: Variable.cpp.o
.PHONY : Variable.o

# target to build an object file
Variable.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Variable.cpp.o
.PHONY : Variable.cpp.o

Variable.i: Variable.cpp.i
.PHONY : Variable.i

# target to preprocess a source file
Variable.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Variable.cpp.i
.PHONY : Variable.cpp.i

Variable.s: Variable.cpp.s
.PHONY : Variable.s

# target to generate assembly for a file
Variable.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/Variable.cpp.s
.PHONY : Variable.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... simulation"
	@echo "... Equation.o"
	@echo "... Equation.i"
	@echo "... Equation.s"
	@echo "... GaussSeidel.o"
	@echo "... GaussSeidel.i"
	@echo "... GaussSeidel.s"
	@echo "... Jacobi.o"
	@echo "... Jacobi.i"
	@echo "... Jacobi.s"
	@echo "... Problem.o"
	@echo "... Problem.i"
	@echo "... Problem.s"
	@echo "... Timer.o"
	@echo "... Timer.i"
	@echo "... Timer.s"
	@echo "... UniformMesh.o"
	@echo "... UniformMesh.i"
	@echo "... UniformMesh.s"
	@echo "... Variable.o"
	@echo "... Variable.i"
	@echo "... Variable.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


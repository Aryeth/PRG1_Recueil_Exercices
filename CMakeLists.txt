# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.
cmake_minimum_required(VERSION 3.16)

project(PRG1_Recueil_Exercices)

set(CMAKE_CXX_STANDARD 20)

# Compilation options for warnings and errors
add_compile_options(-Wall -Wextra -Wpedantic -g)

# Add each exercise as a separate executable
add_executable(ex3 "01 - Introduction/ex04.cpp")
add_executable(ex4 "01 - Introduction/ex04_b.cpp")

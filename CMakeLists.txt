cmake_minimum_required(VERSION 3.6)
project(BST_Assignment1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c bst.c bst.h filefuncs.c filefuncs.h outputFile.h outputFile.c)
add_executable(BST_Assignment1 ${SOURCE_FILES})
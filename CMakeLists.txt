cmake_minimum_required(VERSION 3.6)
project(BST_FileIn)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c bst.c bst.h filefuncs.c filefuncs.h menu.c menu.h)
add_executable(BST_FileIn ${SOURCE_FILES})
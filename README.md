# PA1_WordCounter
##Read Me
_____
-Team      :  White     
-Members   :  Shawn Johnson, Sara Kim, 
              Lena Banks, Stefani Moore
              
-Class     :  Operating Systems UCD           
-HW#       :  PA1 Word Counter               
-Due Date  :  2/6/2017
****
####Description of the program

>Word counter program implemented using a binary search tree in C.

####Source files

>main.c bst.c filefuncs.c bst.h filefuncs.h outputFile.h outputFile.c

####Circumstances of programs

>This program was developed and tested on CLion Version 2016.3.2 and also tested on
>the csegrid using the compile directions below.

>Note: In order to get the correct output file format i.e. myoutputXX.txt, the input
>file must be of the format inputXX.txt where XX is any valid integer.

####How to build and run the program

>Use the following as CMakeLists.txt

    cmake_minimum_required(VERSION 3.6)
    project(BST_FileIn)

    set(CMAKE_C_STANDARD 11)

    set(SOURCE_FILES main.c bst.c filefuncs.c outputFile.c bst.h filefuncs.h outputFile.h)
    add_executable(BST_FileIn ${SOURCE_FILES})
    
>For the csegrid
 
    To Compile:
      gcc -std=c11 main.c bst.c filefuncs.c outputFile.c
    To Execute:
      ./a.out test.txt



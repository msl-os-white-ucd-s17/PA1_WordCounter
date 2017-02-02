# PA1_WordCounter
##Read Me
_____
-Team      :  White     
-Members   :  Shawn Johnson, Sara Kim, 
              Lena Banks, Stefani Moore
              
-Class     :  Operating Systems UCD           
-HW#       :  PA1 Word Counter               
-Due Date  :  2/3/2017
****
####Description of the program

>Word counter program implemented using a binary search tree in C.

####Source files

>main.c bst.c filefuncs.c bst.h filefuncs.h menu.h menu.c

####Circumstances of programs

>Update Me

####How to build and run the program

>Use the following as CMakeLists.txt

    cmake_minimum_required(VERSION 3.6)
    project(PA1_WordCounter)

    set(CMAKE_C_STANDARD 11)

    set(SOURCE_FILES main.c bst.c filefuncs.c bst.h filefuncs.h menu.c menu.h)
    add_executable(PA1_WordCounter ${SOURCE_FILES})
    
>For the csegrid
 
    To Compile:
      gcc -std=c11 main.c bst.c filefuncs.c menu.c
    To Execute:
      ./a.out test.txt




/*
=========================================================================================================

                                        Word Counter

=========================================================================================================
Contributors:			OS Team White - Shawn Johnson, Sara Kim, Lena Banks, Stefani Moore
Last Date Modified:		2-6-2017
Course:					Operating Systems
Assignment:				Word Counter in C - Assigment 1
Description:            This program will function as a text file word counter implemented by using a
                        binary search tree in the C programming language.

Status:					Files merged. Added a lower case conversions to words read from the file, a
                        menu function location in menu.c, and a findNode search function for the BST.

                        The merged files with new function has been compiled and runs successfully
                        via CLion 2016.3.2 and the CSE UNIX grid

                        All file functions tested on CLion with CMake 3.6.3 and GDB 7.11.1 and working properly.
=========================================================================================================
*/
#include <stdbool.h>
#include "filefuncs.h"
#include "outputFile.h"

void main(int argc, char **argv) {
    Node *tree = NULL;          //Instance created for struct BST_Node
    char* fileIn = argv[1];     //User input test file in the format of inputXX.txt
    size_t numElements = 20;
    int wordCount = 0;
    char* arrayOfWords[21];

    if (argc > 1) {
        FILE *file = fopen(fileIn, "r");
        if (file != NULL) {
            char *word = NULL;
            long int s = 0, e = 0, curPos;
            fseek(file, 0, SEEK_END);
            long int sz = ftell(file);  //EOF location
            rewind(file);
            bool persist = true;
            while (persist) {
                s = getStartPos(file);
                e = getEndPos(file);
                if (s >= sz) { //Since fseek resets EOF flag, we must manually check for EOF
                    persist = false;
                    continue;
                }
                word = (char*) malloc(sizeof(char)*((e-s)+1));
                if (word == NULL) {
                    perror("Memory Error!");
                    exit(2);
                }
                else {
                    curPos = ftell(file);
                    fseek(file, s, SEEK_SET);
                    fread(word, sizeof(char), (size_t) e-s, file);
                    word[(e-s)] = '\0'; //Null terminator
                    fseek(file, curPos, SEEK_SET);

                    if(word != "") {
                        word = convertToLower(word);        //convert all char's to lowercase
                        if(wordCount < 20) {
                           arrayOfWords[wordCount] = malloc(strlen(word)+1);
                            strcpy(arrayOfWords[wordCount], word);
                            arrayOfWords[wordCount + 1] = NULL;
                            wordCount++;
                        }
                        else{
                            wordCount = 0;
                            arrayOfWords[20] = NULL;
                            char** shuffArr = shuffleWords(arrayOfWords); //Shuffles words and calls function to add them to BST

                            for(int i = 0; shuffArr[i] != NULL; i++)
                            {
                                insertNode(shuffArr[i], &tree);
                            }
                        }
                    }
                }
            }
           if(tree != NULL)
            {
                writeFile(tree, fileIn);
            }
            deleteBinTree(&tree);       //Delete struct BST_Node instance
            //free(arrayOfWords); //Free the array of words
            fclose(file);
        }
        else {
            printf("Error! Could not open file for reading!");
            exit(1);
        }
    }
    else {
        printf("Error! Input file not specified!\nUSAGE: a.exe FILENAME.txt");
        exit(1);
    }

    exit(0);
}



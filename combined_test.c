
/*
=========================================================================================================

                                        Word Counter

=========================================================================================================
Contributors:			OS Team White
Last Date Modified:		1-31-2017
Course:					Operating Systems
Assignment:				Word Counter in C - Assigment 1
Description:            This program will function as a text file word counter implemented by using a
                        binary search tree in the C programming language.

Status:					Created a Binary Search tree node insertion function, tree traversal, and
                        tree delete function. Created a very simple test case to make sure that the
                        functions are working as expected and so far, so good.

                        Compiles and runs successfully via CLion 2016.3.2 and the CSE UNIX grid

                        All file functions tested on CLion with CMake 3.6.3 and GDB 7.11.1 and working properly.
                        Need to integrate adding node to BST in main function.
=========================================================================================================


*/
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bst.h"

long int getStartPos(FILE *f) {
    int ch;
    long int sPos = -1L; //Initialize to error code
    sPos = ftell(f);

    for (ch = fgetc(f); ch != EOF && !isalpha((char) ch); ch = fgetc(f))
    {  //Only alphabetic letters allowed, no numbers.
        sPos = ftell(f);
    }
    return sPos;
}

long int getEndPos(FILE *f) {
    int ch;
    long int ePos = -1L; //Initialize to error code
    ePos = ftell(f);

    for (ch = fgetc(f); ch != EOF && isalpha((char) ch); ch = fgetc(f))
    {   //Only alphabetic letters allowed, no numbers.
        ePos = ftell(f);
    }
    return ePos;
}


void insertNode(char* iWord, Node** nodePtr){

    int cmpValue;                                       //Holds value for strcmp

    if(*nodePtr == NULL){
        (*nodePtr) = createNode(iWord);                 //Create a new node if nodePtr is not NULL
        if(*nodePtr == NULL){
            printf("%s failed to insert.", iWord);      //If nodePtr is NULL, print error message
        }
    }
    else{
        cmpValue = strcmp(iWord, (*nodePtr)->wordArr);  //Compare words to determine a left or right traversal

        if(cmpValue < 0){
            insertNode(iWord, &(*nodePtr)->left);       //Word < than node, traverse left
        }
        else if(cmpValue > 0){
            insertNode(iWord, &(*nodePtr)->right);      //Word > than node, traverse right
        }
        else{                                           //Word = node word, increment wordCount
         //   printf("Word '%s' incremented by 1\n", iWord);
            (*nodePtr)->wordCount = (*nodePtr)->wordCount + 1;
        }
    }
}


Node *createNode(char* iWord){

    Node *parentNode;
    parentNode = malloc(sizeof(Node));      //allocate memory for the struct Node
    if(!parentNode){                        //If mem allocation fails, print error message and return NULL
        printf("Unable to allocate memory for node.\n");
        return NULL;
    }
    parentNode->wordArr = iWord;            //Set key = to iWord for new Node
    parentNode->wordCount = 1;              //new node wordCount = 1
    parentNode->left = NULL;                //Left and right branches are NULL
    parentNode->right = NULL;

    return parentNode;                      //Return new node
}

void inOrderTraversal(Node* pNode){

    //Recusively traverse all nodes of the tree in order from left to right
    if(pNode != NULL){
        inOrderTraversal(pNode->left);
        printf("\nWord: %s  Count: %d\n", pNode->wordArr, pNode->wordCount);
        inOrderTraversal(pNode->right);
    }
}

void deleteBinTree(Node** nodePtr){

    //Recursively delete all nodes unless binary search tree is empty
    if(*nodePtr != NULL){
        deleteBinTree(&(*nodePtr)->left);
        deleteBinTree(&(*nodePtr)->right);
        free((*nodePtr)->wordArr);
        free((*nodePtr));
    }

}


int main(int argc, char **argv) {
    Node* tree = NULL;
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL) {
            char *word = NULL;
            long int start = 0, end = 0, curPos;
            fseek(file, 0, SEEK_END);
            long int sz = ftell(file);  //EOF location
            rewind(file);
            bool persist = true;


            while (persist) {
                start = getStartPos(file);
                end = getEndPos(file);
                if (start >= sz) { //Since fseek resets EOF flag, we must manually check for EOF
                    persist = false;
                    continue;
                }
                word = (char*) malloc(sizeof(char)*((end-start)+1));
                if (word == NULL)
                {
                    perror("Memory Error!");
                    exit(2);
                }
                else {
                    curPos = ftell(file);
                    fseek(file, start, SEEK_SET);
                    fread(word, sizeof(char), (size_t) end-start, file);
                    word[(end-start)] = '\0'; //Null terminator
                    fseek(file, curPos, SEEK_SET);

             //       printf("ORIGINAL: %s%s", word, "\n");


            // Process to change all words into lower case
                    int i = 0, i2 = 0;
                    char test;
                    char *newWord;      // newWord stores lowercase word

                    newWord = (char*) malloc(sizeof(char)*(strlen(word)+1));
                    if (newWord == NULL)
                    {
                        perror("Memory Error");
                        exit(2);
                    }

                    else {
                         while(word[i]) {
                          test = word[i];
                              if (isupper(test))        // if character is upper change to lower
                               test = tolower(test);
                             newWord[i2] = test;        // Store new character into new word
                            i++;
                            i2++;
                        }
                    }

                 //   printf("LOWER CASE: %s%s", newWord, "\n");
                    insertNode(newWord, &tree);
                    //Create node object here via the pointer to char array 'word'
                }

            }
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

    inOrderTraversal(tree);

    exit(0);
}

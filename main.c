
/*
=========================================================================================================

                                        Word Counter

=========================================================================================================
Contributors:			OS Team White
Last Date Modified:		1-28-2017
Course:					Operating Systems
Assignment:				Word Counter in C - Assigment 1
Description:            This program will function as a text file word counter implemented by using a
                        binary search tree in the C programming language.

Status:					Created a Binary Search tree node insertion function, tree traversal, and
                        tree delete function. Created a very simple test case to make sure that the
                        functions are working as expected and so far, so good.

                        Compiles and runs successfully via CLion 2016.3.2 and the CSE UNIX grid
=========================================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct BST_Node{

    //Node structure for Binary Search Tree
    char *wordArr;
    int wordCount;

    // struct Node* root;
    struct BST_Node* left;
    struct BST_Node* right;

} Node;

//Function Prototypes
void insertNode(char*, Node**);
Node* createNode(char*);
void inOrderTraversal(Node*);
void deleteBinTree(Node**);


int main() {

    //**********************************************************************
    //              TEST CASE
    //**********************************************************************
    Node* tree = NULL;

    char *wordIn1 = "something";
    char *wordIn2 = "else";
    char *wordIn3 = "another";
    char *wordIn4 = "else";

    printf("Adding: %s\n", wordIn);
    insertNode(wordIn1, &tree);

    printf("Adding: %s\n", wordIn2);
    insertNode(wordIn2, &tree);

    printf("Adding: %s\n", wordIn3);
    insertNode(wordIn3, &tree);

    printf("Adding: %s\n", wordIn4);
    insertNode(wordIn4, &tree);

    inOrderTraversal(tree);

    return 0;
}

//BST Functions

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
            printf("Word '%s' incremented by 1\n", iWord);
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
/*
 * BST functions implementation - bst.c
 *
 */
#include "bst.h"

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

    //Recursively traverse all nodes of the tree in order from left to right
    if(pNode != NULL){
        inOrderTraversal(pNode->left);
        printf("\n%s : %d\n", pNode->wordArr, pNode->wordCount);
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
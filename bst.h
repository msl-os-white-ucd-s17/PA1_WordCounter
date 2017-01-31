/*
 * BST class declaration - bst.h
 */

#ifndef WHITEOS_PA1_BST_H
#define WHITEOS_PA1_BST_H

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

void insertNode(char*, Node**);
Node* createNode(char*);
void inOrderTraversal(Node*);
void deleteBinTree(Node**);

#endif //WHITEOS_PA1_BST_H

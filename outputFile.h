//
// Created by Stefani on 1/31/2017.
// Edited to be writeFile not menu

#ifndef BST_FILEOUT_H
#define BST_FILEOUT_H

#include <stdio.h>

#include "bst.h"

void writeFile(Node*, char*);
void writeTreeToFile(FILE* wf, Node* tree);
char* convertToLower(char*);

#endif //BST_FILEOUT_H

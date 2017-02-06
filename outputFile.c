//
// Created by Stefani on 1/31/2017.
// Edited menu.c and menu.h to outputFile.c and outputFile.h
// Included a writeFile function that writes sorted words in order
// to file of the user's choice

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "outputFile.h"

char fileName[100];
FILE *wf;
bool test = false;

void writeFile(Node* tree) {

    // Only have to run file naming once so set bool to false
    // Once bool is true, means output file is created and opened
    while(test == false) {
        printf("\nEnter the name of the output File:\n");
        scanf("%123s", fileName);
        strcat(fileName, ".txt");           // Turn file name of user's choice to .txt

        wf = fopen(fileName, "w");
        if (wf == NULL) {
            printf("ERROR creating file");
            exit(1);
        }
        test = true;
    }
    // Implement the same recursive function as inOrderTraversal
    // to write sorted text into file
        if(tree != NULL) {
            writeFile(tree->left);
            fprintf(wf, "%s Count: %d\n", tree->wordArr, tree->wordCount);
            writeFile(tree->right);
        }
}

char* convertToLower(char* iWord){

   for(int i = 0; iWord[i];i++){
        iWord[i] = (char) tolower(iWord[i]);
    }

    return iWord;
}

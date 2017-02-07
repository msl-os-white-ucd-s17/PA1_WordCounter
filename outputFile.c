//
// Created by Stefani on 1/31/2017.
// Edited menu.c and menu.h to outputFile.c and outputFile.h
// Included a writeFile function that writes sorted words in order
// to file of the user's choice

//Updated Sara's writeToFile to myoutputXX.txt file as requested by instruction on Slack 2/6/17

#include <ctype.h>
#include <string.h>
#include "outputFile.h"



void writeFile(Node* tree, char* fileIn) {


    char outputFile[15]; //Where output will be in the format of myoutputXX.txt
    FILE *wf;

    strcpy(outputFile, "myoutput00.txt"); //char* makes string read-only strcpy required to change XX

    //fileIn should be of the format inputXX.txt as per requirements
    for(int i = 0; i < strlen(fileIn); i++)
    {
        if(isdigit(fileIn[i]))
        {
            outputFile[i+3] = fileIn[i];
        }
    }

        wf = fopen(outputFile, "w");
        if (wf == NULL)
        {
            printf("ERROR creating file");
            exit(1);
        }
        else {
            writeTreeToFile(wf, tree);
            fclose(wf);
        }

}

void writeTreeToFile(FILE* wf, Node* tree)
{
    //Recursively write contents of the tree to the file
    if(tree != NULL)
    {
        writeTreeToFile(wf, tree->left);
        fprintf(wf, "%s : %d\n", tree->wordArr, tree->wordCount);
        writeTreeToFile(wf, tree->right);
    }
}

char* convertToLower(char* iWord){

   for(int i = 0; iWord[i];i++){
        iWord[i] = (char) tolower(iWord[i]);
    }

    return iWord;
}

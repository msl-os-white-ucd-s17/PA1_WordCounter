/*
 * File Functions implementation - filefuncs.c
 *
 */

#include <time.h>
#include <stdlib.h>
#include "filefuncs.h"

long int getStartPos(FILE *f) {
    int ch;
    long int sPos = -1L; //Initialize to error code
    sPos = ftell(f);
    for (ch = fgetc(f); ch != EOF && !isalpha((char) ch); ch = fgetc(f)) {  //Only alphabetic letters allowed, no numbers.
        sPos = ftell(f);
    }
    return sPos;
}

long int getEndPos(FILE *f) {
    int ch;
    long int ePos = -1L; //Initialize to error code
    ePos = ftell(f);
    for (ch = fgetc(f); ch != EOF && isalpha((char) ch); ch = fgetc(f)) {   //Only alphabetic letters allowed, no numbers.
        ePos = ftell(f);
    }
    return ePos;
}

char** shuffleWords(char** arrayOfWords)
{
    srand((unsigned int) time(NULL));
    for(int i = 0; arrayOfWords[i] != NULL; i++)
    {
        //FisherYates shuffle method
        char* temp = arrayOfWords[i];
        int r = rand() % 20; //Generate random number between 0 and 19
        arrayOfWords[i] = arrayOfWords[r];
        arrayOfWords[r] = temp;
    }

    arrayOfWords[20] = NULL;

    return arrayOfWords;
}






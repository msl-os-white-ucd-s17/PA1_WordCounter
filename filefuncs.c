/*
 * File Functions implementation - filefuncs.c
 * Created by: Shawn
 */

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

char** shuffleWords(char** arrayOfWords, int wordCount)
{
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; arrayOfWords[i] != NULL; i++)
    {
        //FisherYates shuffle method
        char* temp = arrayOfWords[i];
        int r = rand() % wordCount; //Generate random number between 0 and wordCount - 1
        arrayOfWords[i] = arrayOfWords[r];
        arrayOfWords[r] = temp;
    }

    arrayOfWords[wordCount] = NULL;

    return arrayOfWords;
}




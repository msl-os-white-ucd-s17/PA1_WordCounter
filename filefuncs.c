/*
 * File Functions implementation - filefuncs.c
 *
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




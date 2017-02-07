/*
 * File Functions declaration - filefuncs.h
 *
 */

#ifndef WHITEOS_PA1_FILEFUNCS_H
#define WHITEOS_PA1_FILEFUNCS_H

#include <stdio.h>
#include <ctype.h>
#include "bst.h"

long int getStartPos(FILE *f);
long int getEndPos(FILE *f);
char** shuffleWords(char**);

#endif //WHITEOS_PA1_FILEFUNCS_H

/*
 * File Functions declaration - filefuncs.h
 * Created by: Shawn
 */

#ifndef WHITEOS_PA1_FILEFUNCS_H
#define WHITEOS_PA1_FILEFUNCS_H


#include<time.h>
#include<stdlib.h>
#include <stdio.h>
#include <ctype.h>

long int getStartPos(FILE *f);
long int getEndPos(FILE *f);
char** shuffleWords(char**, int);

#endif //WHITEOS_PA1_FILEFUNCS_H

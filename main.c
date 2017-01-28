#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

long int getStartPos(FILE *f) {
    int ch;
    long int sPos = -1L; //Initialize to error code
    sPos = ftell(f);
    for (ch = fgetc(f); ch != EOF && !isalpha((char) ch); ch = fgetc(f)) {
        sPos = ftell(f);
    }
    return sPos;
}

long int getEndPos(FILE *f) {
    int ch;
    long int ePos = -1L; //Initialize to error code
    ePos = ftell(f);
    for (ch = fgetc(f); ch != EOF && isalpha((char) ch); ch = fgetc(f)) {
        ePos = ftell(f);
    }
    return ePos;
}



main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file;
        if ((file = fopen(argv[1], "r")) != NULL) {
            char *word = NULL;
            long int s = 0, e = 0, curPos;
            while (!feof(file)) {
                s = getStartPos(file);
                e = getEndPos(file);
                word = (char*) malloc(sizeof(char)*((e-s)+1));
                if (word == NULL) {
                    perror("Memory Error!");
                    exit(2);
                }
                else {
                    curPos = ftell(file);
                    fseek(file, s, SEEK_SET);
                    fread(word, sizeof(char), (size_t) e-s, file);
                    word[(e-s)] = '\0';
                    fseek(file, curPos, SEEK_SET);
                }

            }
            fclose(file);
        }
        else {
            printf("Error! Could not open file for reading!");
            exit(1);
        }
    }
    else {
        printf("Error! Input file not specified!\nUSAGE: ./a.out FILENAME.txt");
        exit(1);
    }
    exit(0);
}
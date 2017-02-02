//
// Created by Stefani on 1/31/2017.
//

#include <ctype.h>
#include "menu.h"

void menu(Node* tree){

    int choice = 3;
    char userInput[64];
    Node* temp = NULL;



    do{
        //Menu Display
        printf("\nMENU\n\n");
        printf("1. Search for Word\n");
        printf("2. Display All Words\n");
        printf("3. Exit Program\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter word to search for\n");
                getchar();         //To ignore the enter after selecting menu option
                fgets(userInput, 63, stdin);

                for(int i = 0; userInput[i];i++){
                    userInput[i] = (char) tolower(userInput[i]);
                }

                userInput[strlen(userInput) - 1] = 0; //Remove newline character at the end of the user input string

                temp = findNode(&tree, userInput);
                if(temp == NULL)
                    printf("\nWord not found.\n");
                else
                    printf("\nWord: %s  Count: %d\n", temp->wordArr, temp->wordCount);
                break;
            case 2:
                inOrderTraversal(tree);     //Print out tree contents in-order
                break;
            case 3:
                break;
            default:
                printf("Invalid option. Try Again\n");
                break;

        }
    }while(choice != 3);
    userInput[63]=0;
}

char* convertToLower(char* iWord){

   for(int i = 0; iWord[i];i++){
        iWord[i] = (char) tolower(iWord[i]);
    }

    return iWord;
}
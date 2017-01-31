//**********************************************************************
//              TEST CASE
//**********************************************************************
#include "bst.h"

int test() {
    Node* tree = NULL;

    char *wordIn1 = "something";
    char *wordIn2 = "else";
    char *wordIn3 = "another";
    char *wordIn4 = "else";

    printf("Adding: %s\n", wordIn1);
    insertNode(wordIn1, &tree);

    printf("Adding: %s\n", wordIn2);
    insertNode(wordIn2, &tree);

    printf("Adding: %s\n", wordIn3);
    insertNode(wordIn3, &tree);

    printf("Adding: %s\n", wordIn4);
    insertNode(wordIn4, &tree);

    inOrderTraversal(tree);

    return 0;
}
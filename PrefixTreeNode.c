#include <stdio.h>

#include "PrefixTreeNode.h"

int readTreeFromFile(PrefixTreeNode* prefixTree, const char* fileName) {
    FILE *file = fopen(fileName, "r");
    char resultString[MAX_STRING_LENGHT];

    if (file == NULL) {
        return -1;
    }

    while (fgets(resultString, sizeof(resultString), file)) {
        addToTree(prefixTree, resultString);
    }

    fclose(file);

    return 0;
}

PrefixTreeNode* addToTree(PrefixTreeNode* prefixTree, const char* word) {
    if (prefixTree == NULL) {
        prefixTree = (PrefixTreeNode*)malloc(sizeof(PrefixTreeNode));
        prefixTree->value = word[0];
        prefixTree->prefixTreeNodes = insert(prefixTree->prefixTreeNodes, word[1], NULL);//TODO
    } else {
        //TODO
    }

    return prefixTree;
}

int isWordInTree(PrefixTreeNode prefixTree, const char* word) {
    //TODO
}


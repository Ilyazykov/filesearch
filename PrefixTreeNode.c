#include <stdio.h>

#include "PrefixTreeNode.h"

int readTreeFromFile(PrefixTreeNode* prefixTree, const char* fileName) {
    FILE *file = fopen(fileName, "r");
    char resultString[MAX_STRING_LENGHT];

    if (file == NULL) {
        return NULL;
    }

    while (fgets(resultString, sizeof(resultString), file)) {
        printf("%s", resultString);
        prefixTree = addToTree(prefixTree, resultString);
    }

    fclose(file);

    return prefixTree;
}

PrefixTreeNode* addToTree(PrefixTreeNode* prefixTree, const char* word) {
    int i = 0;
    PrefixTreeNode* iteratorCurr;
    PrefixTreeNode* iteratorNext;

    if (prefixTree == NULL) {
        prefixTree = (PrefixTreeNode *)malloc(sizeof(PrefixTreeNode));
        prefixTree->isWord = FALSE;
        prefixTree->prefixTreeNodes = NULL;
    }
    iteratorCurr = prefixTree;

    while (word[i] != '\0') {
        iteratorNext = (PrefixTreeNode*)(searchInTree(iteratorCurr->prefixTreeNodes, word[i]));

        if (iteratorNext == NULL) {
            iteratorNext = (PrefixTreeNode *)malloc(sizeof(PrefixTreeNode));
            iteratorNext->isWord = FALSE;
            iteratorNext->prefixTreeNodes = NULL;

            iteratorCurr->prefixTreeNodes = insert(iteratorCurr->prefixTreeNodes, word[i], iteratorNext);
        }
        iteratorCurr = iteratorNext;

        ++i;
    }
    iteratorCurr->isWord = TRUE;

    return prefixTree;
}

int isWordInTree(const PrefixTreeNode* prefixTree, const char* word) {
    int i = 0;
    PrefixTreeNode* iterator = prefixTree;

    while (word[i] != '\0') {
        if (iterator == NULL) {
            return FALSE;
        }
        iterator = (PrefixTreeNode*)(searchInTree(iterator->prefixTreeNodes, word[i]));

        ++i;
    }

    if (iterator->isWord) {
        return TRUE;
    } else {
        return FALSE;
    }
}


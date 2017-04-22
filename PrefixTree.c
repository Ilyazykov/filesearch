#include <stdio.h>

#include "PrefixTree.h"

void addToTree(PrefixTree* prefixTree, const char const * word) {
    //TODO
    printf("%s", word);
}

int readTreeFromFile(PrefixTree* prefixTree, const char const * fileName) {
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

int isWordInTree(PrefixTree prefixTree, const char const * word) {
    //TODO
}


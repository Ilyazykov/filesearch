#include <stdio.h>
#include <string.h>

#include "PrefixTree.h"
#include "Tests.h"

#define EXIT_WORD "exit"

int main(int argc, char* argv[]) {
//    runTests();
    if (argc == 1) {
        printf("Run program with dictionary file path as parameter, please.\n");
        return 0;
    }

    PrefixTreeNode* prefixTree = NULL;
    char* fileName = argv[1];
    char word[MAX_STRING_LENGHT];

    prefixTree = readTreeFromFile(prefixTree, fileName);
    if (prefixTree == NULL) {
        printf("Can't open dictionary file.\n");
        return 0;
    }

    printf(">");
    scanf("%s", &word);
    while (strcmp(word, EXIT_WORD) != 0) {
        if (isWordInTree(prefixTree, word)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        printf(">");
        scanf("%s", &word);
    }

    deletePrefixTree(prefixTree);
    return 0;
}

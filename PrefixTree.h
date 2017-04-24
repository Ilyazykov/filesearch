#ifndef UNTITLED_PREFIXTREE_H
#define UNTITLED_PREFIXTREE_H

#include "RedBlackTree.h"

#define MAX_STRING_LENGHT 20

struct PrefixTree {
    //TODO
};
typedef struct PrefixTree PrefixTree;

void addToTree(PrefixTree* prefixTree, const char const * word);
int readTreeFromFile(PrefixTree* prefixTree, const char const * fileName);
int isWordInTree(PrefixTree prefixTree, const char const * word);

#endif //UNTITLED_PREFIXTREE_H
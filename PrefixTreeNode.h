#ifndef UNTITLED_PREFIXTREE_H
#define UNTITLED_PREFIXTREE_H

#include "RedBlackTree.h"

#define MAX_STRING_LENGHT 20

struct PrefixTreeNode {
    Node* prefixTreeNodes;
    char value;
};
typedef struct PrefixTreeNode PrefixTreeNode;

int readTreeFromFile(PrefixTreeNode* prefixTree, const char* fileName);
PrefixTreeNode* addToTree(PrefixTreeNode* prefixTree, const char* word);
int isWordInTree(PrefixTreeNode prefixTree, const char* word);

#endif //UNTITLED_PREFIXTREE_H
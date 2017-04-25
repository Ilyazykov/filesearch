#ifndef UNTITLED_PREFIXTREE_H
#define UNTITLED_PREFIXTREE_H

#include "RedBlackTree.h"

#define MAX_STRING_LENGHT 20
#define TRUE 1
#define FALSE 0

struct PrefixTreeNode {
    Node* prefixTreeNodes;
    int isWord;
};
typedef struct PrefixTreeNode PrefixTreeNode;

int readTreeFromFile(PrefixTreeNode* prefixTree, const char* fileName);
PrefixTreeNode* addToTree(PrefixTreeNode* prefixTree, const char* word);
int isWordInTree(const PrefixTreeNode* prefixTree, const char* word);

//================================================================

PrefixTreeNode* getNextPrefixTreeNode(PrefixTreeNode* current, char key);

#endif //UNTITLED_PREFIXTREE_H
#ifndef UNTITLED_REDBLACKTREE_H
#define UNTITLED_REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct Node {
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int color;

    char key;
    void* value;
};
typedef struct Node Node;

Node* insert(Node* root, char key, void* value);
void deleteTree(Node* root, void*(*valueDeleteFunction)(void*));
void* searchInTree(const Node* node, char key);

#endif //UNTITLED_REDBLACKTREE_H

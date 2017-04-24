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
void deleteTree(Node* root);

Node* getGrandparent(const Node* const node);
Node* getUncle(const Node* const node);

void rotateLeft(Node *node);
void rotateRight(Node *node);

#endif //UNTITLED_REDBLACKTREE_H

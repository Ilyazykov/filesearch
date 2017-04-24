#include "RedBlackTree.h"

Node* insert(Node* root, void* value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
    }
    //TODO

    return root;
}

Node* getGrandparent(const Node* const node) {
    if ((node != NULL) && (node->parent != NULL)) {
        return node->parent->parent;
    }
    else {
        return NULL;
    }
}

Node* getUncle(const Node* const node) {
    Node* grandparent = getGrandparent(node);
    if (grandparent == NULL) {
        return NULL;
    }
    if (node->parent == grandparent->left) {
        return grandparent->right;
    }
    else {
        return grandparent->left;
    }
}
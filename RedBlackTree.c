#include "RedBlackTree.h"

Node* insert(Node* root, char key, void* value) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->key = key;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
    else if (key < root->key) {
        root->left = insert(root->left, key, value);
        root->left->parent = root;
    } else {
        root->right = insert(root->right, key, value);
        root->right->parent = root;
    }

    return root;
}

void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    root->left = NULL;

    deleteTree(root->right);
    root->right = NULL;

    root->parent = NULL;
    free(root);
}

void* searchInTree(const Node* node, char key) {
    if (node == NULL) {
        return NULL;
    }

    if (key == node->key) {
        return node->value;
    } else if (key < node->key) {
        return searchInTree(node->left, key);
    } else {
        return searchInTree(node->right, key);
    }
}

Node* getGrandparent(const Node* node) {
    if ((node != NULL) && (node->parent != NULL)) {
        return node->parent->parent;
    }
    else {
        return NULL;
    }
}

Node* getUncle(const Node* node) {
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
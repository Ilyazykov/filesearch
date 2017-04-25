#include "RedBlackTree.h"

Node* insert_(Node* currentNode, Node* prevNode, char key, void* value);

Node* getGrandparent(const Node* node);
Node* getUncle(const Node* node);

void rotateLeft(Node *node);
void rotateRight(Node *node);

void insertFixup_case1(Node *node);
void insertFixup_case2(Node *node);
void insertFixup_case3(Node *node);
void insertFixup_case4(Node *node);
void insertFixup_case5(Node *node);

//======================================================================

Node* insert(Node* root, char key, void* value) {
    Node* newNode = insert_(root, NULL, key, value);
    Node* newRoot = root;

    insertFixup_case1(newNode);

    if (root == NULL) {
        newRoot = newNode;
    }

    while (newRoot->parent != NULL) {
        newRoot = newRoot->parent;
    }
    return newRoot;
}

Node* insert_(Node* currentNode, Node* prevNode, char key, void* value) {
    if (currentNode == NULL) {
        currentNode = (Node*)malloc(sizeof(Node));
        currentNode->key = key;
        currentNode->value = value;
        currentNode->color = RED;

        currentNode->left = NULL;
        currentNode->right = NULL;
        currentNode->parent = prevNode;
        if (prevNode != NULL) {
            if (key < prevNode->key) {
                currentNode->parent->left = currentNode;
            } else {
                currentNode->parent->right = currentNode;
            }
        }
        return currentNode;
    }
    else if (key < currentNode->key) {
        return insert_(currentNode->left, currentNode, key, value);
    } else {
        return insert_(currentNode->right, currentNode, key, value);
    }
}

void deleteTree(Node* root, void*(*valueDeleteFunction)(void*)) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left, valueDeleteFunction);
    root->left = NULL;

    deleteTree(root->right, valueDeleteFunction);
    root->right = NULL;

    root->parent = NULL;
    if (valueDeleteFunction != NULL) {
        valueDeleteFunction(root->value);
    }
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

void rotateLeft(Node *node) {
    Node* pivot = node->right;

    pivot->parent = node->parent;
    if (node->parent != NULL) {
        if (node->parent->left == node) {
            node->parent->left = pivot;
        } else {
            node->parent->right = pivot;
        }
    }

    node->right = pivot->left;
    if (pivot->left != NULL) {
        pivot->left->parent = node;
    }

    node->parent = pivot;
    pivot->left = node;
}

void rotateRight(Node *node) {
    Node* pivot = node->left;

    pivot->parent = node->parent;
    if (node->parent != NULL) {
        if (node->parent->left == node) {
            node->parent->left = pivot;
        } else {
            node->parent->right = pivot;
        }
    }

    node->left = pivot->right;
    if (pivot->right != NULL) {
        pivot->right->parent = node;
    }

    node->parent = pivot;
    pivot->right = node;
}

void insertFixup_case1(Node *node) {
    if (node->parent == NULL) {
        node->color = BLACK;
    } else {
        insertFixup_case2(node);
    }
}

void insertFixup_case2(Node *node) {
    if (node->parent->color == BLACK) {
        return;
    } else {
        insertFixup_case3(node);
    }
}

void insertFixup_case3(Node *node) {
    Node* uncle = getUncle(node);

    if ((uncle != NULL) && (uncle->color == RED) && (node->parent->color == RED)) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        Node* grandparent = getGrandparent(node);
        grandparent->color = RED;
        insertFixup_case1(grandparent);
    } else {
        insertFixup_case4(node);
    }
}

void insertFixup_case4(Node *node) {
    Node* grandparent = getGrandparent(node);

    if ((node == node->parent->right) && (node->parent == grandparent->left)) {
        rotateLeft(node->parent);
        node = node->left;
    } else if ((node == node->parent->left) && (node->parent == grandparent->right)) {
        rotateRight(node->parent);
        node = node->right;
    }
    insertFixup_case5(node);
}

void insertFixup_case5(Node *node) {
    Node* grandparent = getGrandparent(node);

    node->parent->color = BLACK;
    grandparent->color = RED;
    if ((node == node->parent->left) && (node->parent == grandparent->left)) {
        rotateRight(grandparent);
    } else {
        rotateLeft(grandparent);
    }
}
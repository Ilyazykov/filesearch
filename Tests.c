#include "Tests.h"

int runTests() {
    printf("\ntest 1: hand initialization\n");
    {
        //arrange
        char key = 'a';
        Node* n = (Node*)malloc(sizeof(Node));

        //act
        n->right = NULL;
        n->left = NULL;
        n->parent = NULL;
        n->color = BLACK;
        n->key = key;

        //assert
        ASSERT(key, n->key);

        free(n);
    }

    printf("\ntest 2: insert to root\n");
    {
        //arrange
        int key = 'a';
        Node* root = NULL;

        //act
        root = insert(root, key);

        //assert
        if (root != NULL) {
            ASSERT(key, root->key)
        }
        else {
            printf("FAIL (not initialized)\n");
        }
    }

    printf("\ntest 3:\n");
    {

    }

    printf("\ntest 4:\n");
    {

    }
    return 0;
}


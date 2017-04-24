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

        n->key = (char)0;
        free(n);
    }

    printf("\ntest 2: insert to root\n");
    {
        //arrange
        char key = 'a';
        int value = 10;
        Node* root = NULL;

        //act
        root = insert(root, key, &value);

        //assert
        if (root != NULL) {
            ASSERT(key, root->key);
        }
        else {
            printf("FAIL (root is not initialized)\n");
        }
    }

    printf("\ntest 3: insert to left and right child\n");
    {
        //arrange
        int value = 10;
        Node* root = NULL;

        //act
        root = insert(root, 'b', &value);
        root = insert(root, 'a', &value);
        root = insert(root, 'c', &value);

        //assert
        if (root != NULL) {
            ASSERT('b', root->key);

            if (root->left != NULL) {
                ASSERT('a', root->left->key);
            } else {
                printf("FAIL (left is not initialized)\n");
            }

            if (root->right != NULL) {
                ASSERT('c', root->right->key);
            } else {
                printf("FAIL (right is not initialized)\n");
            }
        }
        else {
            printf("FAIL (root is not initialized)\n");
        }
    }

    printf("\ntest 4:\n");
    {

    }
    return 0;
}


#include "Tests.h"

int runTests() {
    Node* globalTree = NULL;
    
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
        char key = 'b';
        int value = 10;

        //act
        globalTree = insert(globalTree, key, &value);

        //assert
        if (globalTree != NULL) {
            ASSERT(key, globalTree->key);
        }
        else {
            printf("FAIL (root is not initialized)\n");
        }
    }

    printf("\ntest 3: insert to left\n");
    {
        //arrange
        char key = 'a';
        int value = 10;

        //act
        globalTree = insert(globalTree, key, &value);

        //assert
        if (globalTree->left != NULL) {
            ASSERT(key, globalTree->left->key);
        } else {
            printf("FAIL (left is not initialized)\n");
        }
    }

    printf("\ntest 4: insert to right\n");
    {
        //arrange
        char key = 'c';
        int value = 10;

        //act
        globalTree = insert(globalTree, key, &value);

        //assert
        if (globalTree->right != NULL) {
            ASSERT(key, globalTree->right->key);
        } else {
            printf("FAIL (right is not initialized)\n");
        }
    }

    printf("\ntest 6: deleting tree\n");
    {
        //arrange

        //act
        deleteTree(globalTree);
        globalTree = NULL;

        //assert
        ASSERT(NULL, globalTree);
    }

    return 0;
}


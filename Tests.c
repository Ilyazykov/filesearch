#include "Tests.h"

int runTests() {
    Node* globalTree = NULL;
    int valueLeft  = 1;
    int valueRoot  = 2;
    int valueRight = 3;
    
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

        //act
        globalTree = insert(globalTree, key, &valueRoot);

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

        //act
        globalTree = insert(globalTree, key, &valueLeft);

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

        //act
        globalTree = insert(globalTree, key, &valueRight);

        //assert
        if (globalTree->right != NULL) {
            ASSERT(key, globalTree->right->key);
        } else {
            printf("FAIL (right is not initialized)\n");
        }
    }

    printf("\ntest 5: search key in tree\n");
    {
        //arrange
        char key = 'c';

        //act
        int* value = searchInTree(globalTree, key);

        //assert
        ASSERT(valueRight, *value);
    }

    printf("\ntest 6: search unsearchable key in tree\n");
    {
        //arrange
        char key = 'd';

        //act
        int* value = searchInTree(globalTree, key);

        //assert
        ASSERT(NULL, value);
    }

    printf("\ntest 8: deleting tree\n");
    {
        //arrange

        //act
        deleteTree(globalTree);
        globalTree = NULL;

        //assert
        ASSERT(NULL, globalTree);
    }

    printf("\ntest 9: balance red black tree (abc)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);

        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 10: balance red black tree (acb)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'b', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 11: balance red black tree (bac)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 11: balance red black tree (bca)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 12: balance red black tree (cab)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'b', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 13: balance red black tree (cba)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 14: balance red black tree (bacd)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'd', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    printf("\ntest 15: balance red black tree (bacde)\n");
    {
        //arrange
        globalTree = insert(globalTree, 'b', &valueRight);
        globalTree = insert(globalTree, 'a', &valueRight);
        globalTree = insert(globalTree, 'c', &valueRight);
        globalTree = insert(globalTree, 'd', &valueRight);
        globalTree = insert(globalTree, 'e', &valueRight);


        //act

        //assert
        ASSERT('b', globalTree->key);

        deleteTree(globalTree);
        globalTree = NULL;
    }

    return 0;
}


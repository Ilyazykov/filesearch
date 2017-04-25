#include "Tests.h"

int runTests() {
    printf("RedBlack tree tests:\n");
    {
        Node *globalTree = NULL;
        int valueLeft = 1;
        int valueRoot = 2;
        int valueRight = 3;

        printf("\n\ttest 1: hand initialization\n\t");
        {
            //arrange
            char key = 'a';
            Node *n = (Node *) malloc(sizeof(Node));

            //act
            n->right = NULL;
            n->left = NULL;
            n->parent = NULL;
            n->color = BLACK;
            n->key = key;

            //assert
            ASSERT(key, n->key);

            n->key = (char) 0;
            free(n);
        }

        printf("\n\ttest 2: insert to root\n\t");
        {
            //arrange
            char key = 'b';

            //act
            globalTree = insert(globalTree, key, &valueRoot);

            //assert
            if (globalTree != NULL) {
                ASSERT(key, globalTree->key);
            } else {
                printf("\tFAIL (root is not initialized)\n");
            }
        }

        printf("\n\ttest 3: insert to left\n\t");
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

        printf("\n\ttest 4: insert to right\n\t");
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

        printf("\n\ttest 5: search key in tree\n\t");
        {
            //arrange
            char key = 'c';

            //act
            int *value = searchInTree(globalTree, key);

            //assert
            ASSERT(valueRight, *value);
        }

        printf("\n\ttest 6: search unsearchable key in tree\n\t");
        {
            //arrange
            char key = 'd';

            //act
            int *value = searchInTree(globalTree, key);

            //assert
            ASSERT(NULL, value);
        }

        printf("\n\ttest 8: deleting tree\n\t");
        {
            //arrange

            //act
            deleteTree(globalTree, NULL);
            globalTree = NULL;

            //assert
            ASSERT(NULL, globalTree);
        }

        printf("\n\ttest 9: balance red black tree (abc)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'a', &valueRight);
            globalTree = insert(globalTree, 'b', &valueRight);
            globalTree = insert(globalTree, 'c', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 10: balance red black tree (acb)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'a', &valueRight);
            globalTree = insert(globalTree, 'c', &valueRight);
            globalTree = insert(globalTree, 'b', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 11: balance red black tree (bac)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'b', &valueRight);
            globalTree = insert(globalTree, 'a', &valueRight);
            globalTree = insert(globalTree, 'c', &valueRight);


            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 11: balance red black tree (bca)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'b', &valueRight);
            globalTree = insert(globalTree, 'c', &valueRight);
            globalTree = insert(globalTree, 'a', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 12: balance red black tree (cab)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'c', &valueRight);
            globalTree = insert(globalTree, 'a', &valueRight);
            globalTree = insert(globalTree, 'b', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 13: balance red black tree (cba)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'c', &valueRight);
            globalTree = insert(globalTree, 'b', &valueRight);
            globalTree = insert(globalTree, 'a', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 14: balance red black tree (bacd)\n\t");
        {
            //arrange
            globalTree = insert(globalTree, 'b', &valueRight);
            globalTree = insert(globalTree, 'a', &valueRight);
            globalTree = insert(globalTree, 'c', &valueRight);
            globalTree = insert(globalTree, 'd', &valueRight);

            //act

            //assert
            ASSERT('b', globalTree->key);

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }

        printf("\n\ttest 15: balance red black tree (bacde)\n\t");
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

            deleteTree(globalTree, NULL);
            globalTree = NULL;
        }
    }

    printf("\n\nPrefix tree tests:\n");
    {
        PrefixTreeNode* prefixTreeRoot = NULL;

        printf("\n\ttest 16: first letter in PrefixTree\n\t");
        {
            //arrange

            //act
            prefixTreeRoot = addToTree(prefixTreeRoot, "test");

            //assert
            ASSERT_NOT_EQ(NULL, searchInTree(prefixTreeRoot->prefixTreeNodes, 't'));
        }

        printf("\n\ttest 17: is word in PrefixTree\n\t");
        {
            //arrange

            //act

            //assert
            ASSERT(TRUE, isWordInTree(prefixTreeRoot, "test"));
        }

        printf("\n\ttest 18: is word not in PrefixTree\n\t");
        {
            //arrange

            //act

            //assert
            ASSERT(FALSE, isWordInTree(prefixTreeRoot, "tes"));
        }

        printf("\n\ttest 19: is empty word not in PrefixTree\n\t");
        {
            //arrange

            //act

            //assert
            ASSERT(FALSE, isWordInTree(prefixTreeRoot, ""));
        }

        printf("\n\ttest 20: add word to prefix tree\n\t");
        {
            //arrange

            //act
            prefixTreeRoot = addToTree(prefixTreeRoot, "tom");

            //assert
            ASSERT(TRUE, isWordInTree(prefixTreeRoot, "test"));
        }

        printf("\n\ttest 21: new word in prefix tree\n\t");
        {
            //arrange

            //act

            //assert
            ASSERT(TRUE, isWordInTree(prefixTreeRoot, "tom"));
        }

        printf("\n\ttest 22: word with letter not in prefix tree\n\t");
        {
            //arrange

            //act

            //assert
            ASSERT(FALSE, isWordInTree(prefixTreeRoot, "a"));
        }

        printf("\n\ttest 23: delete prefix tree\n\t");
        {
            //arrange

            //act
            prefixTreeRoot = deletePrefixTree(prefixTreeRoot);

            //assert
            ASSERT(NULL, prefixTreeRoot);
        }
    }

    return 0;
}


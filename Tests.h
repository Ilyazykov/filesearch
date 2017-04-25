#ifndef VKTASK5_TESTS_H
#define VKTASK5_TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RedBlackTree.h"
#include "PrefixTreeNode.h"

#define ASSERT(expected, computed)      \
        if ((expected) == (computed)) { \
            printf("OK\n");             \
        } else {                        \
            printf("FAIL\n");           \
        }

int runTests();

#endif //VKTASK5_TESTS_H

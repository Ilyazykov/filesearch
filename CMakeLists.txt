cmake_minimum_required(VERSION 2.8.4)
project(VKtask5)

set(SOURCE_FILES main.c PrefixTree.h PrefixTree.c RedBlackTree.h RedBlackTree.c Tests.c Tests.h)
add_executable(VKtask5 ${SOURCE_FILES})

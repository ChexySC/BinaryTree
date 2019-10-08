#!/bin/bash
echo "binary_tree_compile_and_link"
gcc -c BinaryTree.c 
gcc -c BinaryTree_Support.c 
gcc -c BinaryTree_Traversal.c 
gcc -c BinaryTree_Operate.c 

gcc BinaryTree.o BinaryTree_Traversal.o BinaryTree_Operate.o BinaryTree_Support.o -o Main_BinaryTree

rm BinaryTree.o BinaryTree_Traversal.o BinaryTree_Support.o BinaryTree_Operate.o

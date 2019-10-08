
#ifndef BINARY_TREE_H
#define BINARY_TREE_H


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
	void* left;
	void* right;
	int idx;
	int data;
}_Node, *_Tree;		

#define TREE_DEPTH 4
#define NODE_NUM ((int)pow(2,TREE_DEPTH)-1)
//#define NULL (void*)0




#endif

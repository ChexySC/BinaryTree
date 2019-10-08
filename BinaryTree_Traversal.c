
#include "BinaryTree_Traversal.h"
#include "BinaryTree_Support.h"
/*
前序遍历：
Forward_Traversal(root)
	Out(root)
	if(left)
		Forward_Traversal(left)
	if(right)
		Forward_Traversal(right)
	else 
		return;
*/
void Forward_Traversal(_Node* node)
{
	if(NULL == node)
	{
		printf("Forward_Traversal Input Null!\n");
		return ;
	}
	Out(node);
	if(node->left)
	{
		Forward_Traversal(node->left);
	}
	if(node->right)
	{
		Forward_Traversal(node->right);
	}
}

/*
中序遍历：
Mid_Traversal(root)
	if(left)
		Mid_Traversal(left)
	Out(root)
	if(right)
		Mid_Traversal(right)
*/
void Mid_Traversal(_Node* node)
{
	if(NULL == node)
	{
		printf("Mid_Traversal Input Null!\n");
		return ;
	}
	if(node->left)
	{
		Mid_Traversal(node->left);
	}
	Out(node);
	if(node->right)
	{
		Mid_Traversal(node->right);
	}
}

/*
后序遍历：
Back_Traversal(root)
	if(left)
		Back_Traversal(left)
	Out(root)
	if(right)
		Back_Traversal(right)
*/
void Back_Traversal(_Node* node)
{
	if(NULL == node)
	{
		printf("Back_Traversal Input Null!\n");
		return ;
	}
	if(node->left)
	{
		Back_Traversal(node->left);
	}
	if(node->right)
	{
		Back_Traversal(node->right);
	}
	Out(node);
}





void InitTraversalData(_Node* node)
{
	int idx = 0;
	
	if(NULL == node)
	{
		printf("InitTraversalData Input Null!\n");
		return ;
	}	
	
	printf("Init: depth:%d, nodeNum:%d\n", TREE_DEPTH, NODE_NUM);
	
	for(idx = 0; idx < NODE_NUM; idx++)
	{
		node[idx].idx = idx+1;
		node[idx].data = idx+1;
		node[idx].left = NULL;
		node[idx].right = NULL;
	}
}

void BinartTree_Traversal(_Node* treeNode)
{
    if(NULL == treeNode)
    {
        printf("BinartTree_Traversal Input NULL!\n");
        return ;
    }
    InitTraversalData(treeNode);
	InitNode_Full(treeNode);
	ShowData(treeNode);
	printf("#####Forward_Traversal#####\n");
	Forward_Traversal(treeNode);
	printf("###########################\n\n");

	printf("#####Mid_Traversal#####\n");
	Mid_Traversal(treeNode);
	printf("###########################\n\n");

	printf("#####Back_Traversal#####\n");
	Back_Traversal(treeNode);
	printf("###########################\n\n");
}

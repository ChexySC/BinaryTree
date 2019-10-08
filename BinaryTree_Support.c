#include "BinaryTree_Support.h"


void InitNode_Full(_Node* node)
{
	int idx = 0;
	
	if(NULL == node)
	{
		printf("node Null!\n");
		return ;
	}	
	
	for(idx = 0; idx < NODE_NUM/2; idx++)
	{
		if(idx*2+2 >= NODE_NUM)
		{
			printf("index Oversize!\n");
			return ;			
		}
		node[idx].left = &node[idx*2+1];
		node[idx].right = &node[idx*2+2];
	}
}

void Out(_Node* node)
{
	if(NULL == node)
	{
		printf("node Null!\n");
		return ;
	}
	printf("idx:%d data:%d\n", node->idx, node->data);
}


int keyCompare(int key, int data)
{
    if(key == data)
    {
        return 0;
    }
    if(key > data)
    {
        return 1;
    }
    else
   {
        return -1;
    }
}

void ShowData(_Node* node)
{
	int idx = 0;
	
	if(NULL == node)
	{
		printf("node Null!\n");
		return ;
	}	
	
	printf("depth:%d, nodeNum:%d\n", TREE_DEPTH, NODE_NUM);
	
	for(idx = 0; idx < NODE_NUM; idx++)
	{
		printf("idx: %d, data:%d\n", node[idx].idx, node[idx].data);
	}
}

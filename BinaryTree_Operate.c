#include "BinaryTree_Operate.h"
#include "BinaryTree_Support.h"

#include "BinaryTree_Traversal.h"




void InitSearchData(_Node* node)
{
	int idx = 0;
	
	if(NULL == node)
	{
		printf("node Null!\n");
		return ;
	}	
	
	printf("Init: depth:%d, nodeNum:%d\n", TREE_DEPTH, NODE_NUM);
	
	for(idx = 0; idx < NODE_NUM; idx++)
	{
        node[idx].idx = idx+1;
		node[idx].left = NULL;
		node[idx].right = NULL;
	}
	node[0].data = 8;
	node[1].data = 4;
	node[2].data = 12;	
	node[3].data = 2;
	node[4].data = 6;
	node[5].data = 10;
	node[6].data = 14;	
	node[7].data = 1;	
	node[8].data = 3;
	node[9].data = 5;
	node[10].data = 7;	
	node[11].data = 9;	
	node[12].data = 11;
	node[13].data = 13;
	node[14].data = 15;			
}


int  BinartTree_Search(_Node* root, int key, _Node** node)
{
    _Node* next = NULL;
    if(NULL == root || NULL == node)
    {
        printf("BinartTree_Search Input NULL!\n");
        return 0;
    }
    //node = &root;     //node 指向了 root 的地址， root 是局部变量，函数退出时空间撤销， 此时访问 node(野指针)指向的空间不存在，报Segmentation fault
    *node = root;       //  root 的值写入 node 指向的地址
    if(0 == keyCompare(key, root->data))
    {
        printf("key in TREE!\n");
        return 1;
    }
    printf("nowIdx: %d Data:%d!\n", root->idx, root->data);
    if(keyCompare(key, root->data) < 0)
    {
        next = root->left;
    }
    else
    {
        next = root->right;
    }
    
    if(next)
    {
        return BinartTree_Search(next, key, node);
    }
    else
    {
        printf("no key in TREE!\n");
        return 0;
    }   
}

void BinartTree_Search_Main(_Node* searchTree)
{
    int key = 0;
    _Node* searchResult;
    _Node* insertTree = NULL;
    if(NULL == searchTree)
    {
        printf("BinartTree_Search_Main Input NULL!\n");
        return ;
    }  
     
    InitSearchData(searchTree);
	InitNode_Full(searchTree);
	ShowData(searchTree);
    while(999 != key)
    {
        printf("Input search key(1-15, 999 to exit):");
        scanf("%d", &key);
        if(BinartTree_Search(searchTree, key, &searchResult))
        {
            printf("BinartTree_Search Success! idx: %d key:%d\n", searchResult->idx, searchResult->data);
        }
        else
        {
            printf("BinartTree_Search Fail: no result!\n");
        }
    }
}


void BinartTree_Insert(_Node** node, int key, int idx)
{
    if(NULL == node)
    {
        printf("BinartTree_Insert Input NULL!\n");
        return ;
    }
    if(NULL == *node)
    {
        *node = (_Node*)malloc(sizeof(_Node));
        (*node)->data = key;
        (*node)->idx = idx;
        (*node)->left = NULL;
        (*node)->right = NULL;
        printf("BinartTree_Insert done! idx:%d key:%d\n", idx, key);
        return;
    }
    if(0 == keyCompare(key, (*node)->data))
    {
        printf("BinartTree_Insert Exist! idx:%d key:%d\n", (*node)->idx, (*node)->data);
        return;
    }
    if(keyCompare(key, (*node)->data) > 0)
    {
        return BinartTree_Insert(&((*node)->right), key, (*node)->idx *2+1);
    }
    else
    {
        return BinartTree_Insert(&((*node)->left), key, (*node)->idx *2);
    }
}

/*向下搜索添加节点，不调整树的结构*/
void BinartTree_Insert_Main()
{
    int key = 0;
    _Node* insertTree = NULL;
    
    while(999 != key)
    {
        printf("Input insert data(999 to exit):");
        scanf("%d", &key);
        BinartTree_Insert(&insertTree, key, 1);
        Forward_Traversal(insertTree);
    }
}


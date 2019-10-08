

#include "BinaryTree.h"
#include "BinaryTree_Traversal.h"
#include "BinaryTree_Operate.h"

_Node traversalNode[NODE_NUM];
_Node searchTree[NODE_NUM];








void main()
{
	BinartTree_Traversal((_Node*)&traversalNode);	
	BinartTree_Insert_Main();
	BinartTree_Search_Main((_Node*)&searchTree);
}


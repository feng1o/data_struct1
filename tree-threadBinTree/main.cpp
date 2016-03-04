#include "threadBinTree.h"



void main()
{
	pBinThreadTree pre = NULL,tree=NULL;
	CreatThreadBinTree(&tree);

	InOrderThreadingBinTree(&pre, tree);
	
	printf("中序遍历结果.....]\n");
	InOrderTravelBinTree(pre);

}
#include "threadBinTree.h"



void main()
{
	pBinThreadTree pre = NULL,tree=NULL;
	CreatThreadBinTree(&tree);

	InOrderThreadingBinTree(&pre, tree);
	
	printf("����������.....]\n");
	InOrderTravelBinTree(pre);

}
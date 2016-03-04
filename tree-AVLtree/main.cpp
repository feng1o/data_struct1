#if 0
#include "avl.h"

int main()
{
	pAVLTree tree = NULL;
	//tree = static_cast<pAVLTree> (CreatEmptyTree(tree));
	tree = (pAVLTree) CreatEmptyTree(tree);

	int high;
	InserAVLTree(&tree, 1, &high);
	//InserAVLTree(&tree, 1, 0);
	travelAVLtree(tree, 1);
	return 0;
}
#endif

#if 01

#include "recursiveAVL.h"
int main()
{

	pAVLTree tree = nullptr;
	tree = (pAVLTree) makeEmptyTree(tree);

	tree = InsertAVLTree(tree, 7);
	tree = InsertAVLTree(tree, 2);
	tree = InsertAVLTree(tree, 1);
	tree = InsertAVLTree(tree, 9);
	tree = InsertAVLTree(tree, 6);
	travelAVLtree(tree, 1);
	return 0;
}

#endif
#include "recursiveAVL.h"

int Higth(pAVLTree tree)
{
	if (tree) return (tree)->depth; 
	else  return -1; 
}

pAVLTree singleRotateToRight(pAVLTree tree)
{
	AVLTreeNode* k1, *k2 = tree;
	k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	k1->depth = Higth(k1->lchild) > Higth(k1->rchild) ? Higth(k1->lchild) + 1 : Higth(k1->rchild) + 1;
	k2->depth = Higth(k2->lchild) > Higth(k2->rchild) ? Higth(k2->lchild) + 1 : Higth(k2->rchild) + 1;
	return k1;
}

pAVLTree doubleRotateToRight(pAVLTree tree)
{
	tree->lchild = singleRotateToRight(tree->lchild);
	return  singleRotateToRight(tree);
	return tree;
}

pAVLTree makeEmptyTree(pAVLTree tree)
{
	if (tree)
	{
		makeEmptyTree(tree->lchild);
		makeEmptyTree(tree->rchild);
	}
	free(tree);
	return tree;
}

void travelAVLtree(pAVLTree tree, int level)
{
	if (tree)
	{
		std::cout << "第" << level << "层: " << tree->value << std::endl;
		travelAVLtree(tree->lchild, level + 1);
		travelAVLtree(tree->rchild, level + 1);
	}
}

AVLTreeNode*  InsertAVLTree(pAVLTree tree, elemType valuex)
{
	if (nullptr == tree)  // 如果是空，直接放入结点
	{
		tree = (pAVLTree)malloc(sizeof(AVLTreeNode));
		def_MyAssert(tree);
		tree->value = valuex;
		tree->lchild = tree->rchild = NULL;
		tree->depth = 0;
		return tree;
	}
	else if (valuex == (tree)->value)
		{
			return NULL;
		}
	else if (valuex < tree->value)
	{
		tree->lchild = InsertAVLTree(tree->lchild, valuex);
		if (Higth(tree->lchild) - Higth(tree->rchild) == 2)
		{
			if (valuex < tree->lchild->value)
				tree = singleRotateToRight(tree);
			else
				tree = doubleRotateToRight(tree);
		}
	}
	else if (valuex > tree->value)
	{
		tree->rchild = InsertAVLTree(tree->rchild, valuex);
		if (Higth(tree->rchild) - Higth(tree->lchild) == 2)
		{
			if (valuex > tree->rchild->value)
				tree = singleRotateToRight(tree);
			else
				tree = doubleRotateToRight(tree);
		}

	}
	tree->depth = Higth(tree->lchild) > Higth(tree->rchild) ?  Higth(tree->lchild)+1 : Higth(tree->rchild)+1;
	return tree;
}

#if 0
#include "avl.h"

void* CreatEmptyTree(pAVLTree tree)
{
	if (tree)
	{
		CreatEmptyTree(tree->lchild);
		CreatEmptyTree(tree->rchild);
	}
	free(tree);
	tree = nullptr;
	return tree;
}
void travelAVLtree(pAVLTree tree, int level)
{
	if (tree)
	{
		std::cout << "第" << level << "层: " << tree->value << std::endl;
		travelAVLtree(tree->lchild, level+1);
		travelAVLtree(tree->rchild, level+1);
	}
}
bool InserAVLTree(pAVLTree* tree, elemType valuex, int* taller)
{
	//diffHigh treeHigh = EQUAL_HIGH;
	if (NULL == *tree)
	{
		*tree = (pAVLTree)malloc(sizeof(AVLTreeNode));
		(*tree)->value = valuex;
		(*tree)->lchild = NULL;
		(*tree)->balance = EQUAL_HIGH;
		*taller = true;
		(*tree)->rchild = NULL;
		return true;
	}
	else
	{
		if (valuex == (*tree)->value)
		{
			*taller = false;
			return false;
		}
		else if (valuex < (*tree)->value)
		{
			if (!InserAVLTree(&((*tree)->lchild), valuex, taller))
				return false;
			else if (*taller) //插入成功，看看哪边变化了，，，
			{
				switch ((*tree)->depth)
				{
				case L_HIGH:  //原来左边高 插入后要改
					LeftBalance(tree);
					*taller = false;
					break;
				case EQUAL_HIGH:
					(*tree)->balance = L_HIGH;
					*taller = false;
					break;
				case R_HIGH:
					(*tree)->balance = EQUAL_HIGH;
					*taller = false;
					break;
				default:
					break;
				}
			}
		}
		else if (valuex > (*tree)->value)
		{
			if (!InserAVLTree(&((*tree)->rchild), valuex, taller))
				return false;
			else if (*taller) //插入成功，看看哪边变化了，，，
			{
				switch ((*tree)->depth)
				{
				case L_HIGH:  //原来左边高 插入后要改
					(*tree)->balance = EQUAL_HIGH;
					*taller = false;
					break;
				case EQUAL_HIGH:
					(*tree)->balance = R_HIGH;
					*taller = false;
					break;
				case R_HIGH:
					RightBalance(tree);
					*taller = false;
					break;
				default:
					break;
				}
			}
		}
	}
}
#endif
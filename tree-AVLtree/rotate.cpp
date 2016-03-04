#if 0
#include "avl.h"

pAVLTree rotateRight(pAVLTree node)
{
	AVLTreeNode* k1 = node->lchild;
	AVLTreeNode* tmp = k1->rchild;
	k1->rchild = node;
	node->lchild = tmp;
	return k1;
}

void LeftBalance(pAVLTree *tree) //要判定插入的 位置，做单旋转，还是双转
{
	AVLTreeNode* nodeLeft, *nodeRight;
	nodeLeft = (*tree)->lchild;
	switch (nodeLeft->balance)
	{
	case L_HIGH:  //就是插入到了 tree左孩子的，左结点上
		(*tree)->balance = nodeLeft->balance = EQUAL_HIGH;
		rotateRight(tree); //需要右转
		break;
	case EQUAL_HIGH:
		(*tree)->balance = L_HIGH;
		break;
	case R_HIGH: //插入的结点在，tree左孩子的右节点，，双转
		nodeRight = (*tree)->rchild;
		switch (nodeRight->balance)
		{
		case L_HIGH:
			(*tree)->balance = R_HIGH;
			nodeRight->balance = EQUAL_HIGH;
			break;
		case EQUAL_HIGH:
			(*tree)->balance = nodeRight->balance = EQUAL_HIGH;
			break;
		case R_HIGH:
			(*tree)->balance = EQUAL_HIGH;
			nodeRight->balance = L_HIGH;
			break;
		}
		nodeRight->balance = EQUAL_HIGH;
		rotateLeft(&(*tree)->lchild); //左旋
		rotateRight(tree);

		break;
	default:
		break;
	}
}




void RightBalance(pAVLTree *tree)
{

}
#endif
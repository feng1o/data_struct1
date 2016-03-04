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

void LeftBalance(pAVLTree *tree) //Ҫ�ж������ λ�ã�������ת������˫ת
{
	AVLTreeNode* nodeLeft, *nodeRight;
	nodeLeft = (*tree)->lchild;
	switch (nodeLeft->balance)
	{
	case L_HIGH:  //���ǲ��뵽�� tree���ӵģ�������
		(*tree)->balance = nodeLeft->balance = EQUAL_HIGH;
		rotateRight(tree); //��Ҫ��ת
		break;
	case EQUAL_HIGH:
		(*tree)->balance = L_HIGH;
		break;
	case R_HIGH: //����Ľ���ڣ�tree���ӵ��ҽڵ㣬��˫ת
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
		rotateLeft(&(*tree)->lchild); //����
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
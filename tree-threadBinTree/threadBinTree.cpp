#define  _CRT_SECURE_NO_WARNINGS
#include "threadBinTree.h"

BinThreadTreeNode* preNode = NULL; //����ǰһ���ڵ�

void CreatThreadBinTree(pBinThreadTree *tree) //����һ����������ǰ�򴴽���
{
	char c;
	scanf("%c", &c);
	if (' '==c)
	{
		*tree = nullptr;
	}
	else
	{
		*tree = (pBinThreadTree)malloc(sizeof(BinThreadTreeNode));
		(*tree)->lflag = Link;
		(*tree)->rflag = Link;
		(*tree)->value = c;

		CreatThreadBinTree(&(*tree)->lchild);
		CreatThreadBinTree(&(*tree)->rchild);
	}
}

/*
function������������ʶ�������Ȼ������ĸ����ڵ����
*/
void InOrderThreadBinTree(pBinThreadTree tree) //��������,
{
	if (tree)  //��� �����٣������ǻ���ȥִ�У���ΪtreeΪ���ˣ�tree->child��Ȼ�����ˣ�������
	{
		InOrderThreadBinTree(tree->lchild);
		if (!tree->lchild)//�����ǿ�,����������
		{
			tree->lflag = Thread;//���� 
			tree->lchild = preNode;//ָ��ǰһ����
		}
		if (!preNode->rchild)//������ǰһ���ڵ�.......
		{
			preNode->rflag = Thread;
			preNode->rchild = tree;
		}
		preNode = tree;
		InOrderThreadBinTree(tree->rchild);
	}
}

//pre��ͷָ�룬��tree�Ǹ�
void InOrderThreadingBinTree(pBinThreadTree *pre, pBinThreadTree tree)
{
	*pre = (pBinThreadTree)malloc(sizeof(BinThreadTreeNode));
	defMyAssert(pre);
	(*pre)->lflag = Link;
	(*pre)->rflag = Thread; //ͷ�����������ǿյģ�������������
	(*pre)->rchild = *pre;
	if (!tree)  //��������ô��headָ���Լ���ok
	{
		(*pre)->lchild = *pre;
	}
	else
	{
		(*pre)->lchild = tree;
		preNode = *pre;
		InOrderThreadBinTree(tree);
		preNode->rchild = *pre;
		preNode->rflag = Thread;
		(*pre)->rchild = preNode;

	}


}
void visitNodePint(char c)
{
	printf("�ڵ�ֵ��:%c", c);
}
void InOrderTravelBinTree(pBinThreadTree head) //δʹ�õݹ�ṹ����ѭ��
{
	pBinThreadTree tree = head->lchild;
	while (tree!=head)
	{
		while (tree->lflag == Link)
		{
			tree = tree->lchild;
		}
		visitNodePint(tree->value);
		while (tree->rflag == Thread && tree->rchild != head)
		{
			tree = tree->rchild;
			visitNodePint(tree->value);
		}
		tree = tree->rchild;
	}
}
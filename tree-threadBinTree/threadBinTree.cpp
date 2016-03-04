#define  _CRT_SECURE_NO_WARNINGS
#include "threadBinTree.h"

BinThreadTreeNode* preNode = NULL; //保存前一个节点

void CreatThreadBinTree(pBinThreadTree *tree) //创建一个二叉树，前序创建的
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
function：中序遍历访问二叉树，然后对树的各个节点进行
*/
void InOrderThreadBinTree(pBinThreadTree tree) //中序线索,
{
	if (tree)  //这个 不可少，否则还是会下去执行，因为tree为空了，tree->child必然出错了，，，，
	{
		InOrderThreadBinTree(tree->lchild);
		if (!tree->lchild)//左孩子是空,就是线索，
		{
			tree->lflag = Thread;//线索 
			tree->lchild = preNode;//指向前一个点
		}
		if (!preNode->rchild)//！！！前一个节点.......
		{
			preNode->rflag = Thread;
			preNode->rchild = tree;
		}
		preNode = tree;
		InOrderThreadBinTree(tree->rchild);
	}
}

//pre是头指针，，tree是根
void InOrderThreadingBinTree(pBinThreadTree *pre, pBinThreadTree tree)
{
	*pre = (pBinThreadTree)malloc(sizeof(BinThreadTreeNode));
	defMyAssert(pre);
	(*pre)->lflag = Link;
	(*pre)->rflag = Thread; //头的右子树就是空的，所以是线索的
	(*pre)->rchild = *pre;
	if (!tree)  //空树，那么就head指向自己就ok
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
	printf("节点值是:%c", c);
}
void InOrderTravelBinTree(pBinThreadTree head) //未使用递归结构，，循环
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
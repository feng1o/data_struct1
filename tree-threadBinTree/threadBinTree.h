#include "stdio.h"
#include "stdlib.h"
//#include "iostream"
#include "assert.h"

#define defMyAssert(x) \
 if(!x) {\
			printf("stack���󣺺���%s,��%d,�ļ�=%s", __FUNCTION__, __LINE__, __FILE__); \
			abort(); \
			}
		

typedef char elemType;

//link��ʾ���Һ��ӵ�ָ��
//thread��ʾǰ����̵�ָ�룬����
typedef enum{ Link, Thread } PointerFlag;//ö�ٴ洢������
typedef struct tag_BinThreadTree BinThreadTreeNode;
typedef BinThreadTreeNode* pBinThreadTree;




struct tag_BinThreadTree {
	elemType value;
	BinThreadTreeNode *lchild;
	BinThreadTreeNode* rchild;
	PointerFlag lflag; //��־���ӣ��������0��������ǰ�ڵ㣬1����������
	PointerFlag rflag;
};

void CreatThreadBinTree(pBinThreadTree *tree);

void InOrderThreadBinTree(pBinThreadTree tree);

void InOrderThreadingBinTree(pBinThreadTree *pre, pBinThreadTree tree);

void InOrderTravelBinTree(pBinThreadTree tree);

void visitNodePint(char c);
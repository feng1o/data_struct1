#include "stdio.h"
#include "stdlib.h"
//#include "iostream"
#include "assert.h"

#define defMyAssert(x) \
 if(!x) {\
			printf("stack错误：函数%s,行%d,文件=%s", __FUNCTION__, __LINE__, __FILE__); \
			abort(); \
			}
		

typedef char elemType;

//link表示左右孩子的指针
//thread表示前驱后继的指针，，，
typedef enum{ Link, Thread } PointerFlag;//枚举存储，，，
typedef struct tag_BinThreadTree BinThreadTreeNode;
typedef BinThreadTreeNode* pBinThreadTree;




struct tag_BinThreadTree {
	elemType value;
	BinThreadTreeNode *lchild;
	BinThreadTreeNode* rchild;
	PointerFlag lflag; //标志左孩子，，如果是0就是链表，前节点，1就是线索：
	PointerFlag rflag;
};

void CreatThreadBinTree(pBinThreadTree *tree);

void InOrderThreadBinTree(pBinThreadTree tree);

void InOrderThreadingBinTree(pBinThreadTree *pre, pBinThreadTree tree);

void InOrderTravelBinTree(pBinThreadTree tree);

void visitNodePint(char c);
#if 0
#ifndef  _AVL_H
#define  _AVL_H
#pragma  once

#include "iostream"
#include "cassert"
#define  def_MyAssert(x)  do{ if(!(x)) \
					std::cout<<__LINE__<<__DATE__<<__FILE__<<__FUNCTION__<<std::endl;\
					abort();} while(0)

//union un_diffHigh{};
typedef enum enu_diffHigh
{
	L_HIGH = -1, EQUAL_HIGH, R_HIGH
}diffHigh;
typedef int elemType;
typedef struct tag_AVLtreeNode  AVLTreeNode;
typedef AVLTreeNode*  pAVLTree;

struct tag_AVLtreeNode
{
	elemType value;
	int balance;
	AVLTreeNode *lchild;
	AVLTreeNode *rchild;
};

void* CreatEmptyTree(pAVLTree tree);
void travelAVLtree(pAVLTree tree, int level);
bool InserAVLTree(pAVLTree* tree, elemType valuex, int * taller);
//pAVLTree rotateRight(pAVLTree node);

void LeftBalance(pAVLTree *tree);
void RightBalance(pAVLTree *tree);

#endif
#endif
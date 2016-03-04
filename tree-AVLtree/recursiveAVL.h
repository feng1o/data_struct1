#ifndef  _AVLr_H
#define  _AVLr_H
#pragma  once

#include "iostream"
#include "cassert"
#define  def_MyAssert(x)  do if(!(x)){ \
					std::cout<<__LINE__<<__DATE__<<__FILE__<<__FUNCTION__<<std::endl;\
					abort();} while(0)
#define  def_HIGHT(tree) do \
		{\
		 if(tree) return (tree)->depth;\
		 else  return -1;\
				} while (0)


typedef int elemType;
typedef struct tag_AVLtreeNode  AVLTreeNode;
typedef AVLTreeNode*  pAVLTree;

struct tag_AVLtreeNode
{
	elemType value;
	int depth;
	AVLTreeNode *lchild;
	AVLTreeNode *rchild;
};

pAVLTree makeEmptyTree(pAVLTree tree);
AVLTreeNode*  InsertAVLTree(pAVLTree tree, elemType valuex);
pAVLTree deleteTree(pAVLTree tree , elemType valuex);
void travelAVLtree(pAVLTree tree, int level);

#endif
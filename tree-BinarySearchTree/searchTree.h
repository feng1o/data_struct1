#ifndef _SEARCHTREE_H
#define _SEARCHTREE_H

#include "iostream"
#include "string"
#include "iomanip"
#include "cassert"

#define  def_MyAssert(x)  \
		if(NULL==x)  {std::cout<<"error"<<__FILE__<<__LINE__<<__FUNCTION__<<"\n";\
		abort();}

typedef int elemType;
typedef struct tag_binSearchTreeNode binSearchTreeNode;
struct tag_binSearchTreeNode {
	elemType value;
	binSearchTreeNode* lchild;
	binSearchTreeNode* rchild;
} ;
typedef binSearchTreeNode* pBinSearchTree;
typedef binSearchTreeNode* pBinSearchTreeNode;


pBinSearchTree CreatAndMakeEmptyBinSearchTree(pBinSearchTree tree);//creat 

pBinSearchTree InsertBinSearchTree(pBinSearchTree tree, elemType value);

pBinSearchTreeNode FindMaxBinSearchTreeNode(pBinSearchTree tree);
pBinSearchTreeNode FindMaxBinSearchTreeNodeRecursive(pBinSearchTree tree);

pBinSearchTreeNode FindMinBinSearchTreeNode(pBinSearchTree tree);

pBinSearchTreeNode DeleteBinSearchTreeNode(pBinSearchTree tree,elemType value);
bool DeleteBinSearchTreeNode2(pBinSearchTree *tree, elemType value);


void TravellBinBinSearchTree(pBinSearchTree tree);

void RecursiveBacktraceTravell(pBinSearchTree tree);

void InsertBinSearchTree2(pBinSearchTree *tree, elemType value);

int GetHeightOfTree(pBinSearchTree tree);


#endif // !_SEARCHTREE_H

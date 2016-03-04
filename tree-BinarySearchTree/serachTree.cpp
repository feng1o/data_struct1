#include "searchTree.h"

//创建过程中防止了内存泄露
pBinSearchTree CreatAndMakeEmptyBinSearchTree(pBinSearchTree tree)
{
	if (NULL!=tree)
	{
		CreatAndMakeEmptyBinSearchTree(tree->lchild);
		CreatAndMakeEmptyBinSearchTree(tree->rchild);
		free(tree);
	}
	return NULL;
}


//和linkstack里面的方法比较，那里的push没有递归，这里使用了递归，创建的时候也是null，如何保证递归能返回？？？的，使用一级指针，二级如何实现？
//传入的tree可能是空，也可能不是空，怎么处理？？？
pBinSearchTree InsertBinSearchTree(pBinSearchTree tree, elemType value)
{
	//pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
	//assert(tempNode != NULL);
	//tempNode->lchild = NULL;
	//tempNode->rchild = NULL;
	//tempNode->value = value;
	if (NULL==tree)
	{
		pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
		assert(tempNode != NULL);
		tempNode->lchild = NULL;
		tempNode->rchild = NULL;
		tempNode->value = value;
		tree = tempNode;
		//return tree;//这三个return，一起才实现了 最后一个return一样的功能
	}
	if (value < tree->value)
	{
		tree->lchild = InsertBinSearchTree(tree->lchild, value);
		//return tree;//这三个return，才实现了 最后一个return一样的功能
	}
	if (value > tree->value)
	{
		tree->rchild = InsertBinSearchTree(tree->rchild, value);
		//return tree;//这三个return，才实现了 最后一个return一样的功能
	}
	return tree;//为什么这个return要放在这里？？？？
	//这个return会最后return最先进入的那个实参，，，，如果放在if里面，return的是最后的，
	//一级级return丢失，返回最后的return
}

/*二级指针---ok*/
void InsertBinSearchTree2(pBinSearchTree *tree, elemType value)
{
	if (NULL == *tree)
	{
		pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
		assert(tempNode != NULL);
		tempNode->lchild = NULL;
		tempNode->rchild = NULL;
		tempNode->value = value;
		*tree = tempNode;
		//return tree;//这三个return，一起才实现了 最后一个return一样的功能
	}
	if (value < (*tree)->value)
	{
		 InsertBinSearchTree2(&(*tree)->lchild, value);
		//return tree;//这三个return，才实现了 最后一个return一样的功能
	}
	if (value >(*tree)->value)
	{
		 InsertBinSearchTree2(&(*tree)->rchild, value);
		//return tree;//这三个return，才实现了 最后一个return一样的功能
	}
}

pBinSearchTreeNode FindMaxBinSearchTreeNode(pBinSearchTree tree)
{
	while (NULL!=tree && NULL!=tree->rchild)
	{
		tree = tree->rchild;
	}
	return tree;
}

//递归实现，，如何返回最后的那个点******************************************************8
static pBinSearchTreeNode rNode = NULL;
pBinSearchTreeNode FindMaxBinSearchTreeNodeRecursive(pBinSearchTree tree)
{
	//pBinSearchTreeNode rNode = tree;//放这里不行，，，多次定义，每次都不一样
	if (NULL != tree && NULL != tree->rchild)
	{
		 FindMaxBinSearchTreeNodeRecursive(tree->rchild);
		 return rNode; //每次return的是一个值
		// return tree;//这个return tree最先的那次，不停递归会回去
	}
	rNode = tree;//最后一次赋值，，，前面不停的return
	//return rNode;
	
}

pBinSearchTreeNode FindMinBinSearchTreeNode(pBinSearchTree tree)
{
	//def_MyAssert(tree);
	if (NULL == tree)
	{
		return tree;
	}
	while (tree->lchild != NULL)
	{
		tree = tree->lchild;
	}
	return tree;
}

//删除节点  懒惰删除法  一个儿子，，多个儿子的
/*
*tip:难点是一层层递归返回一个二叉树的左右孩子，最后改变了这棵树的结构，，，理解，***************************
*/
pBinSearchTreeNode DeleteBinSearchTreeNode(pBinSearchTree tree,elemType value)
{
	def_MyAssert(tree);//对于有递归的，最好不要使用这个assert判定，因为很可能传递的参数结束条件是NULL
	pBinSearchTree tmpNode = NULL;
	if (value < tree->value)
	{
		tree->lchild = DeleteBinSearchTreeNode(tree->lchild, value);//难点是接受返回值一层层返回
	}
	else if (value > tree->value)
	{
		tree->rchild = DeleteBinSearchTreeNode(tree->rchild, value);
	}
	else if (tree->lchild  && tree->rchild )
	{
		tmpNode = FindMinBinSearchTreeNode(tree->rchild);
		tree->value = tmpNode->value;
		tree->rchild = DeleteBinSearchTreeNode(tree->rchild, tmpNode->value);
	}
	else
	{	
		tmpNode = tree;
		if (NULL == tree->lchild)
		{
			tree = tree->rchild;
		}
		else if (NULL == tree->rchild)//此处if和else if区别较大 
		{
			tree = tree->lchild;
		}
		delete tmpNode;
	}
	return tree;//这里每一层的返回均有不同的意义，，，如果递归中没有接受者，那么，中间断层，会返回首部

}
//二级指针
/*这里的层层return会怎么样，到底是如何传送的
这里的return 是个bool值，实际等甲鱼是一个全局变量，最后一层赋值，然后一直返回，返回，返回，并没有朽败
和return tree，区别就很明显了，，*/
bool DeleteNode(pBinSearchTree *tree)
{
	pBinSearchTreeNode currentNode, preNode;
	if ((*tree)->rchild ==NULL)
	{
		currentNode = *tree;
		*tree = (*tree)->lchild;//二级指针  所以changel 
		delete currentNode;
	}
	else if ((*tree)->lchild == NULL)
	{
		currentNode = *tree;
		*tree = (*tree)->rchild;//二级指针  所以changel 
		delete currentNode;
	}
	else
	{
		currentNode = *tree;
		preNode = (*tree)->lchild;
		while (preNode->rchild != NULL)
		{
			currentNode = preNode; //记录要删除节点的前一个节点，，
			preNode = preNode->rchild;//找到节点的左孩子的的最大的右子树点，，
		}
		(*tree)->value = preNode->value;
		//currentNode->rchild = preNode->lchild;
		if (*tree == currentNode)//当左子树没有右子树，只有左子树的时候，
		{
			(*tree)->lchild = preNode->lchild;
		}
		else
		{
			currentNode->rchild = preNode->lchild;//当左子树有右子树的时候，，，，
		}

		delete preNode;
	}
	return true;
}
bool DeleteBinSearchTreeNode2(pBinSearchTree *tree, elemType value)
{
	def_MyAssert(*tree);
	if ((*tree)->value == value)
	{
		/*这里的层层return会怎么样，到底是如何传送的
		这里的return 是个bool值，实际等甲鱼是一个全局变量，最后一层赋值，然后一直返回，返回，返回，并没有朽败
		和return tree，区别就很明显了，，*/
		return DeleteNode(tree);
	}
	else if ((*tree)->value > value)
	{
		return DeleteBinSearchTreeNode2(&(*tree)->lchild, value);
		/*这里的层层return会怎么样，到底是如何传送的
		 这里的return 是个bool值，实际等甲鱼是一个全局变量，最后一层赋值，然后一直返回，返回，返回，并没有朽败
		 和return tree，区别就很明显了，，*/
	}
	else if ((*tree)->value < value)
	{
		 return DeleteBinSearchTreeNode2(&(*tree)->rchild, value);
	}
	//return false;
}








//遍历二叉树
void TravellBinBinSearchTree(pBinSearchTree tree)
{
	if (tree!=NULL)
	{
		TravellBinBinSearchTree(tree->lchild);
		TravellBinBinSearchTree(tree->rchild);
		std::cout << "Travell: " << std::setw(2) << tree->value << std::endl;

	}
}
//回溯遍历二叉树
void RecursiveBacktraceTravell(pBinSearchTree tree)
{
	if (tree==NULL)
	{
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << "Travell: " << std::setw(2) << tree->value << std::endl;
		if (tree->lchild != NULL)
		{
			RecursiveBacktraceTravell(tree->lchild);
		}
		if (tree->rchild!=NULL)
		{
			RecursiveBacktraceTravell(tree->rchild);
		}
	}
}

int GetHeightOfTree(pBinSearchTree tree)
{
	if (NULL == tree)
	{
		return -1;
	}
	else
	{
		return 1 + (GetHeightOfTree(tree->lchild) > GetHeightOfTree(tree->rchild) ? GetHeightOfTree(tree->lchild) : GetHeightOfTree(tree->rchild));
	}
}
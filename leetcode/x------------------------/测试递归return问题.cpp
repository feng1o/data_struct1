/*
*满足条件return，递归中途不return就是最后的return
*结合搜索二叉树中的几个操作，及很容易理解。。。。。。。。
*/

#include "iostream"
#include "string"

using namespace std;

int recusiveTest(int i)
{
	
	if (i==0 || i<0)
	{
		int j = 100;
		return i;
	}
	else if (i%2 == 0)
	{
		recusiveTest(i - 1);
	}
	else if (i%2 == 1)
	{
		recusiveTest(i - 2);
	}
	
}

int recusiveTest2(int i)
{
	//int j = 100;
	if (i == 0 || i < 0)
	{
		return i;
	}
	else if (i % 2 == 0)
	{
		recusiveTest(i - 1);
	}
	else if (i % 2 == 1)
	{
		recusiveTest(i - 2);
	}
	return i; //最直接的返回第一个元素，，，同时能达到返回一层层效果的作用，比如树结构的递归
}
int main()
{
	cout<<recusiveTest(3)<<endl;
	cout << recusiveTest2(3) << endl;
}

/*
//递归实现，，如何返回最后的那个点********全局变量返回******差别在于结构不同****************************8
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
	
}*/

//删除节点  懒惰删除法  一个儿子，，多个儿子的
/*searchTree.cpp
*tip:难点是一层层递归返回一个二叉树的左右孩子，最后改变了这棵树的结构，，，理解，***************************
*/
/*
pBinSearchTreeNode DeleteBinSearchTreeNode(pBinSearchTree tree, elemType value)
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
	else if (tree->lchild  && tree->rchild)
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
*/
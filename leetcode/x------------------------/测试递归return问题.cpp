/*
*��������return���ݹ���;��return��������return
*��������������еļ�������������������⡣��������������
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
	return i; //��ֱ�ӵķ��ص�һ��Ԫ�أ�����ͬʱ�ܴﵽ����һ���Ч�������ã��������ṹ�ĵݹ�
}
int main()
{
	cout<<recusiveTest(3)<<endl;
	cout << recusiveTest2(3) << endl;
}

/*
//�ݹ�ʵ�֣�����η��������Ǹ���********ȫ�ֱ�������******������ڽṹ��ͬ****************************8
static pBinSearchTreeNode rNode = NULL;
pBinSearchTreeNode FindMaxBinSearchTreeNodeRecursive(pBinSearchTree tree)
{
	//pBinSearchTreeNode rNode = tree;//�����ﲻ�У�������ζ��壬ÿ�ζ���һ��
	if (NULL != tree && NULL != tree->rchild)
	{
		 FindMaxBinSearchTreeNodeRecursive(tree->rchild);
		 return rNode; //ÿ��return����һ��ֵ
		// return tree;//���return tree���ȵ��ǴΣ���ͣ�ݹ���ȥ
	}
	rNode = tree;//���һ�θ�ֵ������ǰ�治ͣ��return
	//return rNode;
	
}*/

//ɾ���ڵ�  ����ɾ����  һ�����ӣ���������ӵ�
/*searchTree.cpp
*tip:�ѵ���һ���ݹ鷵��һ�������������Һ��ӣ����ı���������Ľṹ��������⣬***************************
*/
/*
pBinSearchTreeNode DeleteBinSearchTreeNode(pBinSearchTree tree, elemType value)
{
	def_MyAssert(tree);//�����еݹ�ģ���ò�Ҫʹ�����assert�ж�����Ϊ�ܿ��ܴ��ݵĲ�������������NULL
	pBinSearchTree tmpNode = NULL;
	if (value < tree->value)
	{
		tree->lchild = DeleteBinSearchTreeNode(tree->lchild, value);//�ѵ��ǽ��ܷ���ֵһ��㷵��
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
		else if (NULL == tree->rchild)//�˴�if��else if����ϴ� 
		{
			tree = tree->lchild;
		}
		delete tmpNode;
	}
	return tree;//����ÿһ��ķ��ؾ��в�ͬ�����壬��������ݹ���û�н����ߣ���ô���м�ϲ㣬�᷵���ײ�

}
*/
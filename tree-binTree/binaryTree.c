#define  _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
//#include "iostream"
#include "assert.h"

typedef char elemType;
typedef struct tag_BinTreeNode binTreeNode;
typedef  binTreeNode * pBinTree;

struct tag_BinTreeNode
{
	//tag_BinTreeNode() :lchild(NULL), rchild(NULL), data(0){};
	elemType data;
	binTreeNode* lchild, *rchild;
};

//前序遍历输入树
	void CreatBinTree(pBinTree *tree)//二级指针
	{
		char ch ;
		//std::cin >> ch;

		scanf("%c", &ch);
		//std::cout << c << std::endl;
		if (' ' == ch)
		{
			*tree = NULL;
		}
		else
		{
			//*tree = new binTreeNode;//这样需要构造器
			*tree = (pBinTree)malloc(sizeof(binTreeNode));
			assert(*tree != NULL);
			(*tree)->data = ch;
			CreatBinTree(&(*tree)->lchild);
			CreatBinTree(&(*tree)->rchild);
		}
}

	pBinTree CreatBinTree2()//返回指针  不行，需要一层层接受，看搜索二叉树，，为什么？？？
		{
			char ch;
		//	static pBinTree tmptree ;  //static 会导致返回的是最后的一次进入的值，，null
			pBinTree tmptree;
			//std::cin >> ch;

			scanf("%c", &ch);
			//std::cout << c << std::endl;
			if (' ' == ch)
			{
				tmptree = NULL;
				return tmptree;
			
			}
			else
			{
				//*tree = new binTreeNode;//这样需要构造器
				tmptree = (pBinTree)malloc(sizeof(binTreeNode));
				//tmptree = (pBinTree)calloc(1,sizeof(binTreeNode));
				assert(tmptree != NULL);
				tmptree->data = ch;
				tmptree->lchild = NULL;
				tmptree->rchild = NULL;
				printf("插入了= %c\n", tmptree->data);

				CreatBinTree2();
				CreatBinTree2();
			}
			return tmptree;
		}
void VistBinTree(pBinTree tree, int level)
{
	//std::cout << "访问节点 " << tree->data <<"：层数 "<< level << std::endl;
	printf("%c位于第%d层\n", tree->data, level);
}

//遍历二叉树
void PreOrderTravelBinTree(pBinTree tree, int level)
{
	if (tree)
	{
		VistBinTree(tree, level);
		PreOrderTravelBinTree(tree->lchild, level + 1); //这里就是单纯递归，非回溯，回溯会是选择，比如
		PreOrderTravelBinTree(tree->rchild, level + 1);
	}
	else
	{
		printf("递归了]\n");
	}
#if 0
//回溯方法遍历树。。。。
	/*tip：回溯对于扫描二叉树必然是有用的，等价于便利一遍，因为二叉树不存在到一个点的二义性路径*/
	if (tree)
	{
		for (孩子n;i=1;i<=n；i++ )
		{
			VistBinTree(孩子i，level);
			PreOrderTravelBinTree(孩子i，level + 1);
		}
	}

#endif


#if 0
	//回溯方法遍历树,第一次从根扫描到叶子就停止，return实现
	if (tree)
	{
		for (孩子n; i = 1; i <= n；i++)
		{
			VistBinTree(孩子i，level);
			if(PreOrderTravelBinTree(孩子i，level + 1))
				return 1;//要求函数用返回值，bool;这样第一次遍历后返回1，一层层不停返回1，就不会继续for循环了，
			//8皇后问题
		}
	}
	else
		return 1;//配合实现一次搞定 

#endif

}

int main()
{
#ifdef _cplusplus
	printf("c_++\n");
#else
	printf("this is a c program!\n");
#endif // _cplusplus

	//pBinTree tree = NULL;//一级指针，，和对于一级指针形参，传递变量地址区别
	//CreatBinTree(&tree);//二级指针
	//PreOrderTravelBinTree(tree, 1);

	
	pBinTree tree2 = CreatBinTree2();//1级指针
	printf("地址是= %p\n", tree2);  //地址是0000？？？
	PreOrderTravelBinTree(tree2, 1);

	return 0;
}
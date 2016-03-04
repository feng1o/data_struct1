#if 01
//http://blog.chinaunix.net/uid-26983585-id-3219788.html
#include<stdio.h>
#include<stdlib.h>
struct BiTNode {
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;//二叉树的结构 struct BiTNode* rchild;
};
typedef struct BiTNode * BiTree;
void CreatBiTree(BiTree*); //创建二叉树
void PreOrderTraverse(BiTree); // 遍历该二叉树，打印各个节点的值
void main(){
	BiTree T = NULL; //T为根节点
	CreatBiTree(&T);
	PreOrderTraverse(T);
	system("pause");
}
//用先序递归过程建立二叉树
void CreatBiTree(BiTree * T)
{
	char ch;
	ch = getchar();
	if (ch == '*') //如果输入星号则二叉树的节点为空节点
		*T = NULL;
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(struct BiTNode))))
		{
			printf("内存分配失败！");
			return; //如果输入的不是星号。则为新节点分配内存空间
		}
		else
		{
			(*T)->data = ch;
			CreatBiTree(&((*T)->lchild)); //分配成功则接着建立左子树和右子树
			CreatBiTree(&((*T)->rchild));
		}
	}
}


void PreOrderTraverse(BiTree T){
	if (T)
	{
		printf("%c", T->data);;
		if (T->lchild)
			PreOrderTraverse(T->lchild); //遍历该树，输出各个节点的值
		if (T->rchild)
			PreOrderTraverse(T->rchild);
	}
}

/*
二叉树中，个人认为初学者容易犯一下几个错误：
1：创建二叉树，有两类模式：
a: 在main 函数中定义一个BiTree 注意这是个二叉树节点的指针类型；然后将这个参数传递给一个CreatBiTree 函数；
在该函数中递归创建二叉树；代码如下：
*/

void CreatBiTree(BiTree * T) //注意这里用的是二级指针；这个是容易犯错误的地方；

{
	char ch;
	ch = getchar();
	if (ch == '*') //如果输入星号则二叉树的节点为空节点
		*T = NULL;
	else{
		if (!(*T = (BiTree)malloc(sizeof(struct BiTNode)))) {
			printf("内存分配失败！");
			return; //如果输入的不是星号。则为新节点分配内存空间
		}
		else
		{
			(*T)->data = ch;
			CreatBiTree(&((*T)->lchild)); //分配成功则接着建立左子树和右子树
			CreatBiTree(&((*T)->rchild));}
	}
}
/*
b:可以直接在CreatBiTree函数中创建二叉树，并返回二叉树的根 指针；
 如：BiTree T=CreatBiTree（）；代码如下
 */
BiTree CreatBiTree()
{
	char ch;
	BiTNode *pt = NULL;
	ch = getchar();
	if ('*' == ch)
		return NULL;
	else {
		pt = (BiTNode *)malloc(sizeof(BiTNode));
		pt->data = ch;
		pt->lchild = CreatBiTree();
		pt->rchild = CreatBiTree();
		return pt;
	}


	/*
呵呵。。从上边的两个建树过程看来，还是第二个容易理解一点：
不过大部分人，都在疑惑一个问题，那就是在 第一个 （即 A) 的过程中，为什么一定要使用二级指针，而一级为什么就不行呢？？
不是说函数中传递指针，在函数中改变指针的值，就是在改变 实参中的数据信息嘛？？？
额。。。其实吧，上边说的也对，可问题就在这块了。。。问题是，在建立二叉树的过程中，不是改变了形参的值，而是： 改变了形参的指向；而推出该函数后，形参被释放了，那么为形参动态分配的空间，也就没办法释放了，造成了内存泄露问题。。
举个例子吧：
*/
void get_Vale1(char *pt)
{
		pt = (char *)malloc(strlen("sx_liang") + 1);
		strcpy(pt, "sx_liang");
	}
void get_Vale2(char **pt)
	{
		*pt = (char *)malloc(strlen("sx_liang") + 1);
		strcpy(*pt, "sx_liang");
	}

	int main()
	{
		char *pt = NULL;
		get_Vale1(pt); //看看，这里调用的过程中，传递的是一级指针；
		if (NULL == pt) //额。。。。在这里呢，就会执行if 里边的信息了。。。
		{
			cout << "pt is NULL" << endl;
			exit(1);
		}
		else
			cout << pt << endl;
		get_Vale2(&pt); //这里呢，传递的是二级指针，结果呢，就输出了“sx_liang";
		if (NULL == pt)
		{
			cout << "pt is NULL";
		}
	}
/*什么原因呢： 咱开始分析一下：
void get_Vale1(char *M)//这里呢，传递了一个指针，此时，M和 实参 pt 的指向内存的同一块空间，都指向了null;
M=(char *)malloc(strlen("sx_liang")+1); //此时呢，给M的重新开辟了一块空间， 而实参pt 没有变化，还指向NULL；
//就是这里，M 和pt 已经没有联系了，彻底变成了两个指向不同的指针；
strcpy(M,"sx_liang");//退出函数时，因为M是局部变量，在栈中分配的空间，那么M自动销毁，而在堆中为M分配的空间呢，泄露了，没有被释放；是个问题！
void get_Vale2(char **M)//这里呢，传递的是二级指针；此时，M 指向实参，而不是和实参一样指向null；*M 此时才和pt相同，都指向了NULL；注意体会一下；
*M=(char *)malloc(strlen("sx_liang")+1);//在这里呢，*M就是 实参pt ,给*M申请空间，就是在为pt 申请空间；注意体会了；
strcpy(*M,"sx_liang");//推出函数后，M销毁，但是它申请的空间没被释放，但是该空间有pt 指向它，不担心释放问题；
额。。。到这里了，应该就能明白为什么 二叉树的创建过程中 A 办法要使用二级指针了吧。。。。一级指针，每次创建的节点，都没有和头指针root 联系起来，当然就没办法打印了， 而二级呢。。。呵呵。。。就OK了。。。。
就是这样了。。。呵呵。。。*/
#endif
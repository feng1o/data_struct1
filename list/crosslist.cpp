#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string.h>  
using namespace std;
#define ROW 5                  
#define COL 5                  
#define max(x,y) x>y?x:y       

int a[ROW][COL] = {            //稀疏矩阵  
	1, 0, 1, 0, 0,
	0, 1, 0, 0, 0,
	0, 0, 0, 1, 1,
	1, 0, 1, 0, 0,
	0, 1, 0, 0, 0
};

//十字链表数据结构  
typedef struct crossList
{
	int row;
	int col;
	union{                  //共用体,总的头结点用val记录稀疏矩阵非零元素的的个数  
		int val;
		crossList *next;    //其余的节点用next串成循环链表  
	};
	crossList *right;
	crossList *down;
}*pClist;

/*****************************
*p为结构体数组
*p[0]为整个十字链表的头结点
*其余元素都是循环链表的头结点
*每个循环链表既要用right将行元素链接起来，也要使用down将列元素链接起来
******************************/
pClist p[max(ROW, COL) + 1];

//初始化各个循环链表的节点  
void init()
{
	p[0] = (pClist)malloc(sizeof(crossList));  //总链表的头结点  
	p[0]->row = ROW;
	p[0]->col = COL;
	p[0]->val = 8;
	p[0]->next = NULL;
	p[0]->right = p[0];
	p[0]->down = p[0];

	pClist pTemp = p[0];
	for (int i = 1; i<6; i++)                    //各个循环链表的头结点  
	{
		p[i] = (pClist)malloc(sizeof(crossList));
		p[i]->row = 0;
		p[i]->col = 0;
		p[i]->val = 0;
		p[i]->next = pTemp->next;
		pTemp->next = p[i];
		pTemp = p[i];
		p[i]->right = p[i];
		p[i]->down = p[i];
	}
}

//将节点插入到十字链表  
void insertNode(pClist p1)
{
	int i = p1->row, j = p1->col;

	//按行看，在合适位置插入该节点  
	pClist p0 = p[i];
	while (p0->right != p[i] && p0->right->col<j)
		p0 = p0->right;

	p1->right = p0->right;
	p0->right = p1;

	//按列看，在合适位置插入该节点  
	p0 = p[j];
	while (p0->down != p[j] && p0->down->row<i)
		p0 = p0->down;

	p1->down = p0->down;
	p0->down = p1;

}

//循环调用insertNode，将整个数组非零元素插入到十字链表  
void insert()
{
	for (int i = 0; i<ROW; i++)
	{
		for (int j = 0; j<COL; j++)
		{
			if (a[i][j] != 0)
			{
				pClist pNew = (pClist)malloc(sizeof(crossList));
				pNew->row = i + 1;
				pNew->col = j + 1;
				pNew->val = a[i][j];
				pNew->right = pNew;
				pNew->down = pNew;

				insertNode(pNew);
			}
		}
	}
}

//按行输出十字链表内容  
void printList()
{
	for (int i = 1; i<6; i++)
	{
		pClist p0 = p[i];
		while (p0->right != p[i])
		{
			int m = p0->right->row, n = p0->right->col, k = p0->right->val;
			cout << m << " " << n << " " << k << " " << endl;
			p0 = p0->right;
		}
	}
}

int main()
{
	init();
	insert();
	printList();
	return 0;
}
#if 0
#include <iostream>  
using namespace std;
#define N 13  

typedef struct Node
{
	int data;
	Node *next;
}Node, *LinkList;

/* ****************************************************************************/
/**
* @Synopsis  InitLinkList 创建并初始化一个循环列表，每个元素的初始化值为0(逆序插入)
*
* @Param L 链表的头节点
* @Param n 创建链表元素的个数
*/
/* ****************************************************************************/
void InitLinkList(LinkList &L, int n)
{
	L = new Node;
	L->next = L;
	LinkList p;
	for (int j = 0; j < n; ++j)
	{
		p = new Node;
		p->data = 0;          //初始值为零  
		p->next = L->next;    //新节点指向原来的第一个节点  
		L->next = p;          //头节点指向新的节点  
	}
}

/* ****************************************************************************/
/**
* @Synopsis  Magician 魔术师为题求解
*
* @Param L
*/
/* ****************************************************************************/
void Magician(LinkList &L, int n)
{
	LinkList p = L->next;
	p->data = 1;                       //第一张牌是1  
	for (int num = 2; num <= n; ++num)  //依次找到2-n牌的位置  
	{
		int i = 0;
		while (i < num)
		{
			p = p->next;
			if (p->data == 0) ++i;      //该位置有牌应该跳过  
		}
		p->data = num;
	}
}

void Print(LinkList &L)
{
	LinkList p = L->next;
	cout << "Print: ";
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	InitLinkList(L, N);
	Magician(L, N);
	Print(L);
}



#endif
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
* @Synopsis  InitLinkList ��������ʼ��һ��ѭ���б�ÿ��Ԫ�صĳ�ʼ��ֵΪ0(�������)
*
* @Param L �����ͷ�ڵ�
* @Param n ��������Ԫ�صĸ���
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
		p->data = 0;          //��ʼֵΪ��  
		p->next = L->next;    //�½ڵ�ָ��ԭ���ĵ�һ���ڵ�  
		L->next = p;          //ͷ�ڵ�ָ���µĽڵ�  
	}
}

/* ****************************************************************************/
/**
* @Synopsis  Magician ħ��ʦΪ�����
*
* @Param L
*/
/* ****************************************************************************/
void Magician(LinkList &L, int n)
{
	LinkList p = L->next;
	p->data = 1;                       //��һ������1  
	for (int num = 2; num <= n; ++num)  //�����ҵ�2-n�Ƶ�λ��  
	{
		int i = 0;
		while (i < num)
		{
			p = p->next;
			if (p->data == 0) ++i;      //��λ������Ӧ������  
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
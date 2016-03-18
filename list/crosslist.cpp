#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string.h>  
using namespace std;
#define ROW 5                  
#define COL 5                  
#define max(x,y) x>y?x:y       

int a[ROW][COL] = {            //ϡ�����  
	1, 0, 1, 0, 0,
	0, 1, 0, 0, 0,
	0, 0, 0, 1, 1,
	1, 0, 1, 0, 0,
	0, 1, 0, 0, 0
};

//ʮ���������ݽṹ  
typedef struct crossList
{
	int row;
	int col;
	union{                  //������,�ܵ�ͷ�����val��¼ϡ��������Ԫ�صĵĸ���  
		int val;
		crossList *next;    //����Ľڵ���next����ѭ������  
	};
	crossList *right;
	crossList *down;
}*pClist;

/*****************************
*pΪ�ṹ������
*p[0]Ϊ����ʮ�������ͷ���
*����Ԫ�ض���ѭ�������ͷ���
*ÿ��ѭ�������Ҫ��right����Ԫ������������ҲҪʹ��down����Ԫ����������
******************************/
pClist p[max(ROW, COL) + 1];

//��ʼ������ѭ������Ľڵ�  
void init()
{
	p[0] = (pClist)malloc(sizeof(crossList));  //�������ͷ���  
	p[0]->row = ROW;
	p[0]->col = COL;
	p[0]->val = 8;
	p[0]->next = NULL;
	p[0]->right = p[0];
	p[0]->down = p[0];

	pClist pTemp = p[0];
	for (int i = 1; i<6; i++)                    //����ѭ�������ͷ���  
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

//���ڵ���뵽ʮ������  
void insertNode(pClist p1)
{
	int i = p1->row, j = p1->col;

	//���п����ں���λ�ò���ýڵ�  
	pClist p0 = p[i];
	while (p0->right != p[i] && p0->right->col<j)
		p0 = p0->right;

	p1->right = p0->right;
	p0->right = p1;

	//���п����ں���λ�ò���ýڵ�  
	p0 = p[j];
	while (p0->down != p[j] && p0->down->row<i)
		p0 = p0->down;

	p1->down = p0->down;
	p0->down = p1;

}

//ѭ������insertNode���������������Ԫ�ز��뵽ʮ������  
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

//�������ʮ����������  
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
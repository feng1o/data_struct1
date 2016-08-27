#if 0
#include<iostream>  
#include<stdio.h>  
#include<math.h>  

using namespace std;

typedef struct LinkNode
{
	int data;
	LinkNode *next;
}LinkNode;

void InsertSort(LinkNode **phead) //����ָ�룬Ҳ����ָ������ã�����ʹ��һ��ͷ������
{
	// ����Ƿ� ���� ����Ԫ����Ŀ С�� 2 ������  
	if (phead == NULL || *phead == NULL || (*phead)->next == NULL)
		return;
	LinkNode *pCur = *phead;
	int i = 0;
	for (; pCur->next != NULL;)
	{
		// �ó�һ����������  
		LinkNode *pNode = new LinkNode;
		pNode->data = pCur->next->data;
		pNode->next = NULL;
		// Ѱ�ҽ������λ��  
		LinkNode *tmp = *phead;
		// ����ͷ��㣬��ʱ pCur ���ƶ�  
		if ((*phead)->data > pNode->data)
		{
			pNode->next = *phead;
			*phead = pNode;
			LinkNode *DelNode = pCur->next;
			pCur->next = pCur->next->next;
			delete DelNode;
			DelNode = NULL;
			continue;
		}
		else
		{
			// β��  
			if (pNode->data >= pCur->data)
			{
				pCur = pCur->next;
				continue;
			}
			// ����  
			else
			{
				while (tmp != pCur&&tmp->next->data <= pNode->data)
					tmp = tmp->next;
				pNode->next = tmp->next;
				tmp->next = pNode;
				LinkNode *DelNode = pCur->next;
				pCur->next = pCur->next->next;
				delete DelNode;
				DelNode = NULL;
			}
		}
	}
}

#define Num 10 // ����������Ҫ����32������λ���  
int main() {
	int i = 0;
	LinkNode *mylink = NULL; // �������Ϊ�գ�����ǰ���ռ�  
	LinkNode *ptr1 =nullptr, *ptr2 = NULL;
	for (i = 0; i < Num; i++)
	{
		if (mylink == NULL)
		{
			mylink = new LinkNode;
			ptr1 = mylink;
		}
		ptr1->next = NULL;
		if (i % 3 == 0)
			ptr1->data = 3;
		else
			ptr1->data = 5 + pow(-2, i + 1);
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		ptr1 = new LinkNode;
		ptr2->next = ptr1;
	}
	if (mylink != NULL)
		ptr2->next = NULL;
	InsertSort(&mylink);
	LinkNode *tmp = mylink;
	for (i = 0; i < Num; i++)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
	return 0;
}
#endif
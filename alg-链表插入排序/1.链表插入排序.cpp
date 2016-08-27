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

void InsertSort(LinkNode **phead) //二级指针，也可用指针的引用，或者使用一个头，，，
{
	// 链表非法 或者 链表元素数目 小于 2 不排序  
	if (phead == NULL || *phead == NULL || (*phead)->next == NULL)
		return;
	LinkNode *pCur = *phead;
	int i = 0;
	for (; pCur->next != NULL;)
	{
		// 拿出一个待插入结点  
		LinkNode *pNode = new LinkNode;
		pNode->data = pCur->next->data;
		pNode->next = NULL;
		// 寻找结点插入的位置  
		LinkNode *tmp = *phead;
		// 插入头结点，此时 pCur 不移动  
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
			// 尾插  
			if (pNode->data >= pCur->data)
			{
				pCur = pCur->next;
				continue;
			}
			// 乱入  
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

#define Num 10 // 迭代次数不要超过32，避免位溢出  
int main() {
	int i = 0;
	LinkNode *mylink = NULL; // 链表可能为空，不提前给空间  
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
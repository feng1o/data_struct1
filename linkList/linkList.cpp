#include "linkList.h"
#include "stdlib.h"
#include "iostream"


vLinKList * CreatLinkList()
{
	pLinkList list = (pLinkList)malloc(sizeof(pLinkList));
	if (NULL != list)
	{
		std::cout << "creat list :" << list << std::endl;
		list->header.next=NULL;
		list->length = 0;
		return list;
	}
	
}

/*
������Ҫinsert����һ����㣿��
1.�ڴ������һ��null��ʵ�ε�ַ������ջ
2.��ϣ��ÿ�ν��붼�Ա�ͷ������Ӧ�޸ģ�ͬʱʵ���ֲ��ǵ�ַ������£�����
ע�����������ջ�д���������ط������𣬣�������
*/
int InsertNodeLinkList(vLinKList * xlist, int pos, elemType value)
{
	LinkList* list = (pLinkList)xlist;
	int ret = NULL != list ;
	LinkListNode *node = (LinkListNode*)malloc(sizeof(LinkListNode));
	node->value = value;
	//LinkListNode *current = (*list).header.next;//�������current��һ��current�ˣ�ǰ������һ��
	LinkListNode *current = (LinkListNode *)&list->header;
	int i = 0;
	while (i++<pos && current->next != NULL)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	ret ? std::cout << "insert ok  .......\n" : std::cout << "insert failure ..\n";
	list->length++;
	return ret;
}

LinkListNode* GetNodeLinkList(vLinKList * xlist, int pos)
{
	pLinkList list = (pLinkList)xlist;
//	LinkListNode* current = list->header.next;
	LinkListNode* ret = NULL;

	int length = LengthLinkList(xlist);
//	std::cout << "length ::: " << length << std::endl;
	if (list && length >= pos)
	{
		int i = 0;
		LinkListNode* current =(LinkListNode*) &list->header;
		while (i++ < pos)
		{
			current = current->next;
		}
		ret = current;
		
	}
	//std::cout << "get ...\n";
	return ret;
}


int LengthLinkList(vLinKList * xlist)
{
	pLinkList list = (pLinkList)xlist;
	if (list)
	{
		return list->length;
	}
}

LinkListNode* DeleteNodeLinkList(vLinKList * xlist, int pos)
{
	LinkList* list = (LinkList*)xlist;
	if (pos < 1 || list == NULL)
		return 0;
	int i;
	LinkListNode* ret = NULL;
	LinkListNode* current = (LinkListNode*) &list->header;
	for (i = 0; i < pos&&i < LengthLinkList(list);i++)
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	list->length--;
	return ret;
	

}

void PrintListReversingly(vLinKList *xlist)
{
	LinkListNode* list = (LinkListNode*)xlist;
	if (NULL!=list)
	{
		if (list->next!=NULL)
		{
			PrintListReversingly(list->next);
		}
	}
	std::cout <<" PrintListReversingly "<< list->value <<std::endl;
}

void TravelLinkList(vLinKList * xlist)
{
	pLinkList list = (pLinkList)xlist;
	LinkListNode* node = NULL;
	/*for (int i = 1; i <= LengthLinkList(list); i++)
	{
	node = GetNodeLinkList(list, i);
	std::cout << "��ӡ��" << i << "-���ڵ�������: " << node->value << std::endl;
	}*/
	node = list->header.next;
	int j = 1;
	while (node != NULL)
	{
		std::cout << "��ӡ��" << j++ << "-���ڵ�������: " << node->value << std::endl;
		node = node->next;
	}
}

//��������
vLinKList* ReverseLink(vLinKList *xlist) //����һ������Ҳ����ʹ�ö���ָ����ʵ���޸�ָ��
{
	pLinkList list = (pLinkList)xlist;
	if (NULL == list||list->header.next==NULL)
	{
		return list;
	}
	LinkListNode* p1, *p2, *p3;
	p1 = list->header.next; //����ط��ǵ�һ���ڵ㣬��
	p2 = p1->next;//�ڶ����ڵ�
	//p3 = p2->next;
	p1->next = NULL; //�ѵ�һ���ڵ�ĺ����ڵ�����null����ΪҪ������
	while (NULL != p2) //p2�ڵ㲻Ϊnull
	{
		p3 = p2->next;  //ȡ��p2�����ڵ㣬��p1,p2����
		p2->next = p1; //�ؼ������θı���ڵ�ĺ���
		p1 = p2;
		p2 = p3;
	}
	list->header.next = p1;

	return list;

}
/* ʵ��¥��
ListNode * ReverseList(ListNode *head){
	ListNode *pre=NULL,*tmp;
	while(head){
	tmp=head->next;
	head->next=pre;
	pre=head;
	head=tmp;
	}
	return pre;
	}
	*/
//ͨ������ָ��ʵ�ֵ�����������
void PReverseLink(vLinKList** xlist)
{
	pLinkList list = (pLinkList)*xlist;
	if (xlist == NULL || list == NULL)
		return;
	LinkListNode *p1, *p2, *p3;
	p1 = list->header.next;
	p2 = p1->next;
	p1->next = NULL;
	while (NULL!=p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	//list->header.next->next = NULL;
	list->header.next = p1;

}

void SortLinkList(vLinKList *xlist)
{
	pLinkList list = (pLinkList)xlist;
	if (list == nullptr || list->length == 1)
		return ;
	LinkListNode* p1 = list->header.next;
	LinkListNode* p2 = nullptr;
	elemType temp;
	while (p1!=nullptr)
	{
		p2 = p1->next;
		while (p2 != nullptr)
		{
			if (p1->value < p2->value)
			{
				temp = p1->value;
				p1->value = p2->value;
				p2->value = temp;
			}
			p2 = p2->next;

		}
		p1 = p1->next;
	}
}
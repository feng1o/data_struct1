#include "circleLinkList.h"


#include "stdio.h"
#include "malloc.h"
#define Circlelist void  
typedef struct _tag_Circle_ListNode CircleListnode;

		#if 01
		/*
		�ڵ�pointer yu����
		*/
		struct _tag_Circle_ListNode
		{
			CircleListnode* next; //ֻ��һ��ָ�룬ΪʲôҪ����ṹ�᣿������
		};
		#endif

//ͷ���
typedef struct Circle_List
{
	int length;
	CircleListnode header; // CircleListnode��һ���ṹ�ᣬΪʲôҪ����һ����ͷ���أ�
}TCirclelist;

//Ԫ��
struct Circle_List_value
{
	int value;
	CircleListnode header;
};

Circlelist* Creat_Circle_List()
{
	TCirclelist* ret;
	ret = (TCirclelist*)malloc(sizeof(TCirclelist));
	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;//������壡����
	}
	return ret;
}

void Destroy_Circle_List(Circlelist *list)
{
	free(list);
}

void Clear_Circle_List(Circlelist* list)
{
	TCirclelist* slist = (TCirclelist*)list; //�������Ҫ
	if (slist != NULL)
	{
		slist->length = 0;
		slist->header.next = NULL;
	}
}

int Circle_List_Length(Circlelist * list)
{
	TCirclelist* slist = (TCirclelist*)list;
	int length = -1;
	if (slist != NULL)
	{
		length = slist->length;
	}
	return length;

}



int Insert_Circle_List(Circlelist* list, CircleListnode * node, int pos)
{
	TCirclelist* slist = (TCirclelist*)list;
	int ret = -1;
	if (slist != NULL && pos >= 0 && node != NULL) //node������null����
	{
		int i;
		ret = slist != NULL && pos >= 0 && node != NULL;
		//	CircleListnode * current = slist->header;
		CircleListnode* current = (CircleListnode*)slist; //��������壡��������
		for (i = 0; i< pos&& current->next != NULL; i++)
		{
			current = current->next;
		}
		current->next = node;
		node->next = current->next;

		//////////////////////////////////////////////////////////////////////////
		if (0 == slist->length) //����ģ�ѭ���ˣ���һ������������һ����
		{
			node->next = node;
		}
		slist->length++;
	}
	return ret;
}

CircleListnode* Get_Circle_Node(Circlelist* list, int pos)
{
	TCirclelist* slist = (TCirclelist*)list;
	int i;
	CircleListnode * ret = NULL;        //���б�Ҫ
	//if (slist != NULL && pos >=0 && pos <= slist->length)
	if (slist != NULL && pos >= 0)         //ѭ���˲���ҪС��length��
	{
		CircleListnode* current = (CircleListnode*)slist;
		for (i = 0; i < pos && current->next != NULL; i++)
		{
			current = current->next;
		}
		ret = current->next;

	}
	return ret;
}

CircleListnode* Delet_Circle_List(Circlelist* list, int pos)
{
	TCirclelist* slist = (TCirclelist*)list;
	CircleListnode* ret = NULL;
	/****************�ҵ���β�Ľ�㣬ע��ͷheader.next****************************************/
	CircleListnode* firstNode = (CircleListnode*)slist->header.next;
	CircleListnode* lastNode = (CircleListnode*)Get_Circle_Node(slist, slist->length - 1);
	/************************************************************************/
	if (slist != NULL && pos >= 0) //&& pos <= slist->length����ȥ����
	{
		int i;
		CircleListnode* current = slist->header.next;
		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}
		//	return current;
		ret = current->next;
		current->next = current->next->next;
		slist->length--;

		/*  ���ɾ����һ��Ԫ�أ����ƶ�ͷ������һ����  */
		if (firstNode == ret)
		{
			slist->header.next = ret->next;
			lastNode->next = ret->next;
		}
		if (slist->length == 0)
		{
			slist->header.next = NULL;
		}
		/*                                                                      */
	}
	return ret;
}



void main()
{
	Circlelist* list = Creat_Circle_List();
	struct Circle_List_value v1, v2, v3, v4;
	v1.value = 1;
	v2.value = 2;
	v3.value = 3;
	v4.value = 4;

	struct Circle_List_value vv[3];
	int j;
	for (j = 0; j <= 3; j++)
	{
		vv[j].value = j + 2;
		printf("%d\n", vv[j].value);
	}

	int k = 2;
	for (; k<4; k++)
	{
		printf(" %d\n", vv->value);
		struct Circle_List_value *vvaddr = (struct Circle_List_value*) (vv + 1);
		printf("%d\n \n", vvaddr);
	}

	Insert_Circle_List(list, (CircleListnode*)&v1, 0);
	Insert_Circle_List(list, (CircleListnode*)&v2, 0);

	int i = 0;
	for (; i <= Circle_List_Length(list); i++)
	{
		struct Circle_List_value* pv = (struct Circle_List_value*)Get_Circle_Node(list, i);
		printf("pv = %d\n", pv->value);
	}

	printf("yes\n");

}

#include "circleLinkList.h"


#include "stdio.h"
#include "malloc.h"
#define Circlelist void  
typedef struct _tag_Circle_ListNode CircleListnode;

		#if 01
		/*
		节点pointer yu定义
		*/
		struct _tag_Circle_ListNode
		{
			CircleListnode* next; //只有一个指针，为什么要设个结构提？？？？
		};
		#endif

//头结点
typedef struct Circle_List
{
	int length;
	CircleListnode header; // CircleListnode是一个结构提，为什么要设置一个接头体呢？
}TCirclelist;

//元素
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
		ret->header.next = NULL;//这个意义！！！
	}
	return ret;
}

void Destroy_Circle_List(Circlelist *list)
{
	free(list);
}

void Clear_Circle_List(Circlelist* list)
{
	TCirclelist* slist = (TCirclelist*)list; //这个很重要
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
	if (slist != NULL && pos >= 0 && node != NULL) //node不等于null意义
	{
		int i;
		ret = slist != NULL && pos >= 0 && node != NULL;
		//	CircleListnode * current = slist->header;
		CircleListnode* current = (CircleListnode*)slist; //这里的意义！！！！！
		for (i = 0; i< pos&& current->next != NULL; i++)
		{
			current = current->next;
		}
		current->next = node;
		node->next = current->next;

		//////////////////////////////////////////////////////////////////////////
		if (0 == slist->length) //加入的，循环了，第一个处理后面插入一样的
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
	CircleListnode * ret = NULL;        //很有必要
	//if (slist != NULL && pos >=0 && pos <= slist->length)
	if (slist != NULL && pos >= 0)         //循环了不需要小于length了
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
	/****************找到收尾的结点，注意头header.next****************************************/
	CircleListnode* firstNode = (CircleListnode*)slist->header.next;
	CircleListnode* lastNode = (CircleListnode*)Get_Circle_Node(slist, slist->length - 1);
	/************************************************************************/
	if (slist != NULL && pos >= 0) //&& pos <= slist->length可以去掉了
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

		/*  如果删除第一个元素，就移动头结点的下一个点  */
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

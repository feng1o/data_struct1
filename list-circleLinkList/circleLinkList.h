#ifndef _LINK_LIST_HEADER_
#define _LINK_LIST_HEADER_

#define Linklist void  

/*
节点pointer yu定义
*/
typedef struct _tag_Link_ListNode Linklistnode;
struct _tag_Link_ListNode
{
	Linklistnode* next; //只有一个指针，为什么要设个结构提？？？？
};


Linklist* Creat_Link_List();

Linklistnode* Get_Link_Node(Linklist* list, int pos);

void Clear_Link_List(Linklist* list);

void  Destroy_Link_List(Linklist *list);

int Link_List_Length(Linklist * list);

int Insert_Link_List(Linklist* list, Linklistnode * node, int pos); //为什么是int？？？

Linklistnode*  Delet_Link_List(Linklist* list, int pos);

#endif
#ifndef _LINK_LIST_HEADER_
#define _LINK_LIST_HEADER_

#define Linklist void  

/*
�ڵ�pointer yu����
*/
typedef struct _tag_Link_ListNode Linklistnode;
struct _tag_Link_ListNode
{
	Linklistnode* next; //ֻ��һ��ָ�룬ΪʲôҪ����ṹ�᣿������
};


Linklist* Creat_Link_List();

Linklistnode* Get_Link_Node(Linklist* list, int pos);

void Clear_Link_List(Linklist* list);

void  Destroy_Link_List(Linklist *list);

int Link_List_Length(Linklist * list);

int Insert_Link_List(Linklist* list, Linklistnode * node, int pos); //Ϊʲô��int������

Linklistnode*  Delet_Link_List(Linklist* list, int pos);

#endif
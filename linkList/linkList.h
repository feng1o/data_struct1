#ifndef _LINKLIST_H
#define _LINKLIST_H
typedef void vLinKList;
typedef int elemType;
typedef struct _linkListNode LinkListNode;

struct _linkListNode
{
	LinkListNode * next;
	elemType  value;
};

typedef struct _LinkList
{
	LinkListNode header;
	int length;
}LinkList;
typedef LinkList* pLinkList;

vLinKList* CreatLinkList();

void ClearLinkList(vLinKList *xlist);
void DestroyLinkList(vLinKList* xlist);

//int InsertNodeLinkList(vLinKList* xlist, int pos, LinkListNode * xnode);
int InsertNodeLinkList(vLinKList* xlist, int pos, elemType value);
LinkListNode* DeleteNodeLinkList(vLinKList * xlist, int pos);

LinkListNode* GetNodeLinkList( vLinKList* xlist, int pos);

//int LengthLinkList(const vLinKList* xlist);
int LengthLinkList( vLinKList* xlist);

void PrintListReversingly(vLinKList *xlist);

vLinKList* ReverseLink(vLinKList *xlist);
void PReverseLink(vLinKList** xlist);

void TravelLinkList(vLinKList * xlist);

void SortLinkList(vLinKList *xlist);
#endif

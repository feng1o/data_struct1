#include "seqList.h"
#define  AVAILABLE -1
using namespace  std;
vSeqList* creatSeqList(int capacity)
{
	if (capacity<=0)
	{
		return nullptr;
	}
	pSeqList slist = NULL;
	slist= (pSeqList)malloc(sizeof(seqList) + sizeof(seqListNode)*capacity);
	if (NULL==slist)
	{
		fprintf(stderr, "creat error \n");
		return slist;
	}
	slist->capacity = capacity;
	slist->length = 0;
	slist->next = 0;
	for (int i = 0; i < capacity; ++i)
		slist->node[i].next = AVAILABLE;
	return slist;
}

void clearSeqList(vSeqList *vlist)
{
	pSeqList slist = (pSeqList)vlist;
	if (NULL != slist)
		slist->length = 0;
}

void destroySeqList(vSeqList* vlist)
{
	free(vlist);
}

bool isFullSeqList(vSeqList *vlist)
{
	pSeqList slist = (pSeqList)vlist;
	if (NULL != slist && slist->length == slist->capacity)
		return true;
	else
		return false;
}
bool InsertNodeLinkList(vSeqList* vlist, int pos, elemType value)
{
	if (isFullSeqList(vlist)){
		cerr << "full  can not insert\n";
		return false;
	}
	pSeqList slist = (pSeqList)vlist;
	if (NULL == slist || pos >= slist->capacity)
		return false;
	int i = 1;
	int inpos = -1;
	int current = slist->next;
	while (i<slist->length && i<pos)
	{
		++i;
		current = slist->node[current].next;
	}
	for (int i = 0; i < slist->capacity;++i)
		if (slist->node[i].next == AVAILABLE)
		{
			inpos = i;
			break;
		}
	slist->node[inpos].next = slist->node[current].next;
	slist->node[inpos].value = value;
	slist->node[current].next = inpos;
	slist->length++;
	return true;
}
void travelSeqList(vSeqList *vlist)
{
	pSeqList slist = (pSeqList)vlist;
	
	if (NULL != slist)
	{
		int current = slist->next;
		cout << "第1个下标是 " << current << " value " << slist->node[current].value << endl;
		for (int i = 0; i < slist->length-1; ++i)
		{
			current = slist->node[current].next;
			cout << "第"<<i+2<<"个下标是 " << current << " value " << slist->node[current].value << endl;
			
		}
	}
}

int main()
{
	seqList * list =(pSeqList) creatSeqList(10);
	list->next = 8;
	list->node[8].value = 8;
	list->node[8].next = 5;
	list->length++;
	cout << list->length << endl;
	InsertNodeLinkList(list, 9, 5);
	cout << list->length << endl;
	InsertNodeLinkList(list, 9, 6);
	cout << list->length << endl;
	InsertNodeLinkList(list, 9, 6);  
	travelSeqList(list);
	cout << list->node[1].next << endl;

	cout << isalpha('1');

}
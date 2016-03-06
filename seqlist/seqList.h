#ifndef _SEQLIST_H
#define  _SEQLIST_H
#include "iostream"
#include "string"
#include "stdio.h"

typedef void vSeqList;
typedef void vSeqListNode;

typedef struct tag_seqList seqList;
typedef seqList* pSeqList;
typedef struct tag_seqListNode seqListNode;
typedef int elemType;

struct tag_seqListNode
{
	elemType value;
	unsigned next;
};

struct tag_seqList
{	
	int capacity; //bukeshao
	int length;
	int next;
	seqListNode node[]; //这个地方malloc情况，注意分析  后门如何引用的？？？？
};

vSeqList * creatSeqList(int capacity);

void clearSeqList(vSeqList *vlist);

void destroySeqList(vSeqList* vlist);

bool isFullSeqList(vSeqList *vlist);

bool insertSeqList(vSeqList* vlist, int pos, elemType value);

vSeqListNode* deletSeqList(vSeqList * list, int pos);

vSeqListNode* getSeqListNode(vSeqList* vlist, int pos);

void travelSeqList(vSeqList *vlist);


#endif
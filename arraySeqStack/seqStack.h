#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include "iostream"
#include "cstdio"
#include "memory"
#include "cassert"

#define  defEmptyTOS (-1)

typedef void vSeqStack;
typedef int elemType;

typedef struct tag_SeqStack
{
	int capacity;
	int length;
	int topOfStack;
	elemType *node;
	//elemType array[]; //���ʹ�����飬����ط�Ҫע���ֹ��λ�����⣬����
}seqStack;


vSeqStack * CreatSeqStack(int capacity,vSeqStack* vstack);
bool IsEmpty(vSeqStack * vstack);
bool IsFull(vSeqStack * vstack);

void Push(elemType elem);

elemType Pop(vSeqStack *vstack);














#endif // !_SEQSTACK_H



#ifndef _MYQUEUE_C_
#define _MYQUEUE_C_

#include "iostream"
#include "stdio.h"
#include "stdlib.h"

typedef int dataType;
typedef struct tag_QueueNode myQueue;

struct tag_QueueNode
{
	int front;
	int rear;
	int capacity;
	dataType data[];//����������

};

void InitQueue(myQueue* queue, int capacity);
void InitPQueue(myQueue* *queue, int capacity);

bool IsEmpty(myQueue * queue);

bool IsFull(myQueue * queue);

void EnQueue(myQueue* queue,dataType data);

dataType DeQueue(myQueue* queue); //ͨ������ֵ��ֵ��̫�ã���һ����Ҫ��ֵ�ͱȽ��鷳�����ض����أ�

void TravelQueue(myQueue* queue);
#endif // !_MYQUEUE_C_

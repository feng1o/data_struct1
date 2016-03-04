#ifndef  _LINKPRIQUEUE_H
#define  _LINKPRIQUEUE_H

#include "stdlib.h"
#include "iostream"
#include "iomanip"
#include "cassert"

typedef int dataType;
typedef struct tag_priLinkQueue priLinkQueue;
typedef priLinkQueue priLinkQueueNode;
typedef priLinkQueue* pPriLinkQueue;
struct tag_priLinkQueue
{
	int priority;
	dataType num;
	priLinkQueue* next;
};

pPriLinkQueue initPriLinkQueue();

pPriLinkQueue enPriLinkQueue(pPriLinkQueue pqueue, dataType num, int priority);

//��Ϊ������Ҳ��ı�ͷ����������Ҫôʹ�ö���ָ�룬Ҫô����ͷ���
pPriLinkQueue dePriLinkQueue(pPriLinkQueue pqueue, priLinkQueueNode* pout);

pPriLinkQueue freePriLinkQueue(pPriLinkQueue pqueue);

void travelPriLinkQueue(pPriLinkQueue pqueue);

void sortPriLinkQueue(pPriLinkQueue queue);//���򣬲���ı�ͷ���������践�أ�ֻ�Ǹı�������ֵ

pPriLinkQueue insertEnPriLinkQueue(pPriLinkQueue queue,dataType num,int priority);
#endif // !1

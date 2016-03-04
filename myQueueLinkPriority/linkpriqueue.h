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

//因为出队列也会改变头，所以这里要么使用二级指针，要么返回头结点
pPriLinkQueue dePriLinkQueue(pPriLinkQueue pqueue, priLinkQueueNode* pout);

pPriLinkQueue freePriLinkQueue(pPriLinkQueue pqueue);

void travelPriLinkQueue(pPriLinkQueue pqueue);

void sortPriLinkQueue(pPriLinkQueue queue);//排序，不会改变头，所以无需返回，只是改变了链表值

pPriLinkQueue insertEnPriLinkQueue(pPriLinkQueue queue,dataType num,int priority);
#endif // !1

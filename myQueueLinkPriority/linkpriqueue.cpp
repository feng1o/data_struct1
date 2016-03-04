#include "linkpriqueue.h"

pPriLinkQueue initPriLinkQueue()
{
	return NULL;
}

pPriLinkQueue enPriLinkQueue(pPriLinkQueue pqueue, dataType num, int priority)
{
	priLinkQueue *queue = (pPriLinkQueue)malloc(sizeof(priLinkQueue));
	assert(queue != NULL);
	queue->num = num;
	queue->priority = priority;
	queue->next = NULL;
	if (pqueue == nullptr)
	{
		pqueue = queue;
		return pqueue;
	}
	else
	{
		pPriLinkQueue temp = pqueue;
		while (temp->next!=nullptr) //zhao到尾结点
		{
			temp = temp->next;
		}
		temp->next = queue;
	}
	return pqueue;
}

pPriLinkQueue dePriLinkQueue(pPriLinkQueue pqueue, priLinkQueueNode* pout)
{
	if (nullptr == pqueue)
	{
		return nullptr;
	}
	pout->num = pqueue->num;
	pout->priority = pqueue->priority;
	pPriLinkQueue ptmp = pqueue;
	pqueue = ptmp->next;
	free(ptmp);
	ptmp = NULL;

	return pqueue;
}
void travelPriLinkQueue(pPriLinkQueue pqueue)
{
	if (pqueue == NULL )
	{
		return;
	}
	else
	{
		std::cout << "打印队列： " << "num值： " << pqueue->num << "  优先级： " << pqueue->priority << std::endl;
		travelPriLinkQueue(pqueue->next);
	}
}
//可使用二级指针
pPriLinkQueue freePriLinkQueue(pPriLinkQueue pqueue)
{
	if (pqueue == nullptr)
	{
		return pqueue;
	}
	else if (pqueue->next == nullptr)
	{
		free(pqueue);
		pqueue = NULL;
		return pqueue;
	}
	else
	{
		pPriLinkQueue p1 = pqueue, p2 = nullptr;
		while (p1->next != nullptr)
		{
			p2 = p1->next;
			p1->next = p2->next;
			free(p2);
			p2 = nullptr;
		}
		free(pqueue);
		pqueue = nullptr;
		return pqueue;
	}
}

//冒泡排序的
void sortPriLinkQueue(pPriLinkQueue queue)
{
	if (queue==nullptr || queue->next==nullptr)
	{
		return;
	}
	else
	{
		priLinkQueueNode* node1 = queue;
		priLinkQueueNode* node2 = queue;
		while (node1->next!=nullptr)
		{
			node2 = node1->next;
			while (node2!=nullptr)
			{
				if (node2->priority > node1->priority)
				{
					dataType tmpdata = node2->num;
					node2->num = node1->num;
					node1->num = tmpdata;

					int tmppri = node2->priority;
					node2->priority = node1->priority;
					node1->priority = tmppri;
				}
				node2 = node2->next;
			}
			node1 = node1->next;
		}
		return;
	}
}

pPriLinkQueue insertEnPriLinkQueue(pPriLinkQueue queue, dataType num, int priority)
{
	pPriLinkQueue pqueue = (pPriLinkQueue)malloc(sizeof(priLinkQueueNode));
	assert(pqueue != nullptr);
	pqueue->num = num;
	pqueue->priority = priority;

	if (queue == nullptr)
	{
		pqueue->next = NULL;
		queue = pqueue;
		return queue;
	}
	else
	{
		if (pqueue->priority > queue->priority)//首部插入
		{
			pqueue->next = queue;
			queue = pqueue;//zhe个理解，前面右值后面又赋值
			return queue;
		}
		else
		{
			pPriLinkQueue pnode = queue;
			while (pnode->next!=NULL) //尾部插入
			{
				pnode = pnode->next;
			}
			if (pnode->priority >= pqueue->priority)
			{
				pqueue->next = nullptr;
				pnode->next = pqueue;
				return queue;
			}
		}
		{
			pPriLinkQueue p1,p2;
			p1 = p2 = nullptr;
			p1 = queue;
			while (p1->next != nullptr)
			{
				p2 = p1->next;
				if (p1->priority >= pqueue->priority && pqueue->priority > p2->priority)
				{
					pqueue->next = p2;
					p1->next = pqueue;
					return queue;
				}
				else
				{
					p1 = p1->next;
				}
			}
		}

	}
	
}
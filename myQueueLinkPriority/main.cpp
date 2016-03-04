#if 01
#include "linkpriqueue.h"

int main()
{
#if 0
	pPriLinkQueue queue = initPriLinkQueue();
	queue = enPriLinkQueue(queue, 1, 1);
	queue = enPriLinkQueue(queue, 2, 2);
	queue = enPriLinkQueue(queue, 3, 3);
	std::cout << "遍历一结果为................\n";
	travelPriLinkQueue(queue);

	sortPriLinkQueue(queue);
	std::cout << "sort后.遍历一结果为................\n";
	travelPriLinkQueue(queue);
	//queue = freePriLinkQueue(queue);

	int i = 0;
	while (queue != NULL)
	{
		i++;
		std::cout << "\n出队列第"<<i<<"个.......\n";
		//priLinkQueueNode * pout = NULL;
		priLinkQueueNode * pout = (priLinkQueueNode *)malloc(sizeof(priLinkQueueNode));
		queue = dePriLinkQueue(queue, pout);
		std::cout << "chu 队列： " << "num值： " << pout->num << "  优先级： " << pout->priority << std::endl;
		std::cout << "chu队列后的遍历.....\n";
		travelPriLinkQueue(queue);
	}
#endif


#if 01
	//使用插入排序插入队列情况
	pPriLinkQueue queue = initPriLinkQueue();

	queue = insertEnPriLinkQueue(queue, 1, 4);
	std::cout << "\n";
	travelPriLinkQueue(queue);

	queue = insertEnPriLinkQueue(queue, 2, 20);
	std::cout << "\n";
	travelPriLinkQueue(queue);

	queue = insertEnPriLinkQueue(queue, 03, 20);
	std::cout << "\n";
	travelPriLinkQueue(queue);

	queue = insertEnPriLinkQueue(queue, 11, 4);
	std::cout << "\n";
	travelPriLinkQueue(queue);

	queue = insertEnPriLinkQueue(queue, 3, 4);
	std::cout << "\n";
	travelPriLinkQueue(queue);

	sortPriLinkQueue(queue);
	std::cout << "\nsort后.遍历一结果为................\n";
	travelPriLinkQueue(queue);
	//queue = freePriLinkQueue(queue);

	int i = 0;
	while (queue != NULL)
	{
		i++;
		std::cout << "\n出队列第" << i << "个.......\n";
		//priLinkQueueNode * pout = NULL;
		priLinkQueueNode * pout = (priLinkQueueNode *)malloc(sizeof(priLinkQueueNode));
		queue = dePriLinkQueue(queue, pout);
		std::cout << "chu 队列： " << "num值： " << pout->num << "  优先级： " << pout->priority << std::endl;
		std::cout << "chu队列后的遍历.....\n";
		travelPriLinkQueue(queue);
	}
#endif
	return 0;
}
#endif


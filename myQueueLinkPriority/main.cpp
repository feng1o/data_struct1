#if 01
#include "linkpriqueue.h"

int main()
{
#if 0
	pPriLinkQueue queue = initPriLinkQueue();
	queue = enPriLinkQueue(queue, 1, 1);
	queue = enPriLinkQueue(queue, 2, 2);
	queue = enPriLinkQueue(queue, 3, 3);
	std::cout << "����һ���Ϊ................\n";
	travelPriLinkQueue(queue);

	sortPriLinkQueue(queue);
	std::cout << "sort��.����һ���Ϊ................\n";
	travelPriLinkQueue(queue);
	//queue = freePriLinkQueue(queue);

	int i = 0;
	while (queue != NULL)
	{
		i++;
		std::cout << "\n�����е�"<<i<<"��.......\n";
		//priLinkQueueNode * pout = NULL;
		priLinkQueueNode * pout = (priLinkQueueNode *)malloc(sizeof(priLinkQueueNode));
		queue = dePriLinkQueue(queue, pout);
		std::cout << "chu ���У� " << "numֵ�� " << pout->num << "  ���ȼ��� " << pout->priority << std::endl;
		std::cout << "chu���к�ı���.....\n";
		travelPriLinkQueue(queue);
	}
#endif


#if 01
	//ʹ�ò����������������
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
	std::cout << "\nsort��.����һ���Ϊ................\n";
	travelPriLinkQueue(queue);
	//queue = freePriLinkQueue(queue);

	int i = 0;
	while (queue != NULL)
	{
		i++;
		std::cout << "\n�����е�" << i << "��.......\n";
		//priLinkQueueNode * pout = NULL;
		priLinkQueueNode * pout = (priLinkQueueNode *)malloc(sizeof(priLinkQueueNode));
		queue = dePriLinkQueue(queue, pout);
		std::cout << "chu ���У� " << "numֵ�� " << pout->num << "  ���ȼ��� " << pout->priority << std::endl;
		std::cout << "chu���к�ı���.....\n";
		travelPriLinkQueue(queue);
	}
#endif
	return 0;
}
#endif


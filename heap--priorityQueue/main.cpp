#include "heap.h"

int main()
{
	pPriorityQueue heap = initPriorityQueue(def_CAPACITY);
	insertPriorityQueue(heap, 1);
	insertPriorityQueue(heap, 9);
	insertPriorityQueue(heap, 7);
	insertPriorityQueue(heap, 5);
	insertPriorityQueue(heap, 6);
	insertPriorityQueue(heap, 3);
	insertPriorityQueue(heap, 4);
	insertPriorityQueue(heap, 13);
	insertPriorityQueue(heap, 23);
	insertPriorityQueue(heap, 12);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		insertPriorityQueue(heap, rand() % 1000);
	}

	deleteMinElem(heap);
	travelPriorityQueue(heap);
	return 0;
}
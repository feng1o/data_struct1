#include "heap.h"

#if 01
pPriorityQueue initPriorityQueue(int capacity)
{
	if (capacity < 1)
		return NULL;
	pPriorityQueue heap = (pPriorityQueue)calloc(sizeof(priorityQueue) + sizeof(elemType)*capacity, sizeof(char));
	//pPriorityQueue heap = (pPriorityQueue)calloc(1, sizeof(priorityQueue) + sizeof(elemType)*capacity); //0k
	//pPriorityQueue heap = (pPriorityQueue)malloc(sizeof(priorityQueue) + sizeof(elemType)*capacity);
	//assert(heap == nullptr);
	def_MyAssert(heap);
	heap->capacity = capacity;
	heap->size = 0;
	heap->element = (elemType*)(heap + 1);
	//for (int i = 0; i < capacity; i++) //初始化
		//heap->element[i] = 0;
				/*				SeqList* Creat_list(int capacity) //这里不可以是 List* Creat_list(int capacity) 声明中是！！！！！可以返回一个指针给void*！ { List* ret = NULL; if (capacity >= 0) { // List* ret =  不可以在此处定义，否则如果capacity为0时候，这个程序运行出错
									ret = (List*)malloc(sizeof(List) + sizeof(ListNode)*capacity);

									//意义深刻，现有个sruct 结构提，后面跟着的是listnode；
								}
								if (ret != NULL)
								{
									ret->capacity = capacity;
									ret->length = 0;
				ret->node = (ListNode*)(ret + 1);//加1的意思是跳过结构提直接指向第一个node元素！！！
								}
								return ret;
							}
					*/
	return heap;
}
#endif

#if 0
pPriorityQueue initPriorityQueue(int capacity)
{
	if (capacity < 1)
		return NULL;
	pPriorityQueue heap = (pPriorityQueue)(sizeof(priorityQueue));
	def_MyAssert(heap);
	heap->capacity = capacity;
	heap->size = 0;
	heap->element = (elemType *)malloc(sizeof(elemType)*(capacity+1)); //int *element 可，柔性数组不可

	return heap;
}
#endif

void insertPriorityQueue(pPriorityQueue heap, elemType elem)
{
	if (NULL == heap || isFull(heap)) return;
	if (isEmpty(heap))  //no sentinel at 0; this is needed;
	{
		heap->element[0] = elem;
		(heap->size)++;
		return;
	}
	int i;
	for (i = heap->size; elem < heap->element[i / 2] && i!=0 ; i = i / 2) //没i!=0,如果0元素最小，或者最大，都可能死循环
	{
		heap->element[i] = heap->element[i / 2]; //
	}
	heap->element[i] = elem;
	heap->size++; //
}

elemType deleteMinElem(pPriorityQueue heap)
{
	if (NULL == heap || isEmpty(heap))
	{
		perror("error, no element to delete!\n");
		return INT_MAX;  //如果把第0个元素作为标志比较好，直接返回....
	}
	elemType minElem = heap->element[0];
	elemType LastElem = heap->element[heap->size - 1];
	std::cout << "lastelme =" << LastElem << std::endl;
	int i = 0;
	int lchild;
	int rchild = 2 * i + 2;
	while (rchild <= heap->size - 1)
	{
		lchild = 2 * i + 1;
		rchild = 2 * i + 2;
		if (LastElem <= heap->element[rchild] && LastElem <= heap->element[lchild])  //最后这个元素如果小于左右孩子，肯定不用比较了，直接拿上来就ok
			break;;
		//if (heap->element[lchild] < heap->element[rchild] && LastElem > heap->element[lchild])
		if (heap->element[lchild] < heap->element[rchild] )
		{
			heap->element[i] = heap->element[lchild];
			i = lchild;
		}
		else
		{
			heap->element[i] = heap->element[rchild];
			i = rchild;
		}

	}
	heap->element[i] = LastElem;
	heap->size--;
	return minElem;
}


void travelPriorityQueue(pPriorityQueue heap)
{
	std::cout << "heap.size = " << heap->size << std::endl;
	int size = heap->size;
	int i = 0;
	while (i<size)
	{
		std::cout << heap->element[i++] << std::endl;
	}
	std::cout << "..............0ver \n";
}


bool isFull(pPriorityQueue heap)
{
	return heap->size == heap->capacity ? true : false;
 } 
bool isEmpty(pPriorityQueue heap)
{
	return !heap->size;
}
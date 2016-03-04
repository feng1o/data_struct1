#include "myqueue.h"
#include "cassert"

void InitQueue(myQueue* queue,int capacity)//capaciyt必须的
{
	//queue->capacity = capacity;//放在malloc前面是error的
	//queue = (myQueue*)malloc(sizeof(myQueue)*queue->capacity);//会怎么样？？？测试下
#ifdef _list_
	queue = (myQueue*)malloc(sizeof(myQueue)+sizeof(dataType)*queue->capacity);
#endif
	queue->capacity = capacity;
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
	return;
}
void InitPQueue(myQueue* *queue, int capacity)
{
	//(*queue)->capacity = capacity;//放在malloc后面，否则，在未分配内存的时候就使用必然出错了
	//(*queue) = (myQueue*)malloc(sizeof(myQueue)*(*queue)->capacity);
	(*queue) = (myQueue*)malloc(sizeof(myQueue) + sizeof(dataType)*capacity);
	(*queue)->capacity = capacity;

	assert((*queue) != NULL);
	(*queue)->front = 0;
	(*queue)->rear = 0;
	return;
}

bool IsEmpty(myQueue * queue)
{
	return queue->front == queue->rear;
}

bool IsFull(myQueue * queue)
{
	return queue->rear == queue->capacity - 1;
}

void EnQueue(myQueue* queue, dataType data)
{
	if (IsFull(queue))
	{
		std::cout << "full queue \n\n";
		return;
	}
	std::cout << "enqueue  ok! \n";
	queue->data[queue->rear] = data;
	queue->rear++;
	return;

}

dataType DeQueue(myQueue* queue)
{
	if (IsEmpty(queue))
	{
		std::cout << "empty quee \n\n";
		return 0; //通过返回值不好
	}
	std::cout << "de  quee \n";
	dataType tmp = queue->data[queue->front];
	queue->front++;
	return tmp;
}

void TravelQueue(myQueue* queue)
{
	while (queue->front!=queue->rear)
	{
		std::cout << queue->data[queue->front++] << std::endl;
	}
}

/*
注意：代码执行完后会发生“变量附近堆栈崩溃Stack around the variable 'queue' was corrupted.
因为，此处没有分配堆栈，但是，做了堆栈操作，因为队列的节点包含一个数组，这个数组为分配空间，
强行操作了，，，并且赋值，不是传递地址给她
*/
int main()
{
	//myQueue **pQueue = nullptr;//必须分配空间，null是错误的，只要使用指针做实参，必须是已经分配的
	//InitPQueue(pQueue, 10);
#if 01
	myQueue queue ;  //代码和二叉树中的二级指针形参，创建一个指针tree=null，然后传递&treee,插入malloc分配内存的区别
	InitQueue(&queue, 10);//变量是可以的，传递其指针
	EnQueue(&queue, 1);
	EnQueue(&queue, 2);
	EnQueue(&queue, 3);
	dataType data1 = DeQueue(&queue);
	TravelQueue(&queue);
	//std::cout << data1 << std::endl;
#endif
#if 0
#define  _list_
	myQueue *queue = (myQueue *)malloc(sizeof(myQueue));//代码和二叉树中的二级指针形参，创建一个指针tree=null，然后传递&treee,插入malloc分配内存的区别
	InitQueue(queue, 10);//变量是可以的，传递其指针
	/*对于一级指针的形参，如果在函数内部有内存分配，这样是无法实现的，必须二级或者通过返回指针来实现
	或者通过在结构里面不使用柔性数组结构，进入函数里面不再是整体malloc，而是把结构里面的指针部分给malloc内存，追加分配*/
#endif
	
#if 0
	//myQueue *queue2 = (myQueue *)malloc(sizeof(myQueue));
	myQueue *queue2 = NULL;
	InitPQueue(&queue2, 10);//变量是可以的，传递其指针
	EnQueue(queue2, 1);
	dataType data1 = DeQueue(queue2);
#endif
	return 0;
}
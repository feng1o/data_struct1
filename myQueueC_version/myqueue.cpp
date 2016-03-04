#include "myqueue.h"
#include "cassert"

void InitQueue(myQueue* queue,int capacity)//capaciyt�����
{
	//queue->capacity = capacity;//����mallocǰ����error��
	//queue = (myQueue*)malloc(sizeof(myQueue)*queue->capacity);//����ô��������������
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
	//(*queue)->capacity = capacity;//����malloc���棬������δ�����ڴ��ʱ���ʹ�ñ�Ȼ������
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
		return 0; //ͨ������ֵ����
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
ע�⣺����ִ�����ᷢ��������������ջ����Stack around the variable 'queue' was corrupted.
��Ϊ���˴�û�з����ջ�����ǣ����˶�ջ��������Ϊ���еĽڵ����һ�����飬�������Ϊ����ռ䣬
ǿ�в����ˣ��������Ҹ�ֵ�����Ǵ��ݵ�ַ����
*/
int main()
{
	//myQueue **pQueue = nullptr;//�������ռ䣬null�Ǵ���ģ�ֻҪʹ��ָ����ʵ�Σ��������Ѿ������
	//InitPQueue(pQueue, 10);
#if 01
	myQueue queue ;  //����Ͷ������еĶ���ָ���βΣ�����һ��ָ��tree=null��Ȼ�󴫵�&treee,����malloc�����ڴ������
	InitQueue(&queue, 10);//�����ǿ��Եģ�������ָ��
	EnQueue(&queue, 1);
	EnQueue(&queue, 2);
	EnQueue(&queue, 3);
	dataType data1 = DeQueue(&queue);
	TravelQueue(&queue);
	//std::cout << data1 << std::endl;
#endif
#if 0
#define  _list_
	myQueue *queue = (myQueue *)malloc(sizeof(myQueue));//����Ͷ������еĶ���ָ���βΣ�����һ��ָ��tree=null��Ȼ�󴫵�&treee,����malloc�����ڴ������
	InitQueue(queue, 10);//�����ǿ��Եģ�������ָ��
	/*����һ��ָ����βΣ�����ں����ڲ����ڴ���䣬�������޷�ʵ�ֵģ������������ͨ������ָ����ʵ��
	����ͨ���ڽṹ���治ʹ����������ṹ�����뺯�����治��������malloc�����ǰѽṹ�����ָ�벿�ָ�malloc�ڴ棬׷�ӷ���*/
#endif
	
#if 0
	//myQueue *queue2 = (myQueue *)malloc(sizeof(myQueue));
	myQueue *queue2 = NULL;
	InitPQueue(&queue2, 10);//�����ǿ��Եģ�������ָ��
	EnQueue(queue2, 1);
	dataType data1 = DeQueue(queue2);
#endif
	return 0;
}
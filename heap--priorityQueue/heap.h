#ifndef _HEAP_H
#define _HEAP_H

#include "iostream"
#include "string"
#include "cassert"
#include "memory"
#include "iomanip"

#define  def_MyAssert(x)  do{ if(!(x)) \
										{std::cout<<__LINE__<<__DATE__<<__FILE__<<__FUNCTION__<<std::endl;\
										abort();}} while(0)
#define  def_CAPACITY 100000
#define  elemType  int 
typedef  struct str_HeapStruct  priorityQueue;
typedef  priorityQueue*  pPriorityQueue;

struct str_HeapStruct{
	int capacity;
	int size;
	elemType* element;//����ɲ������ַ�ʽ�����ڴ棬
						//��һ��һ��malloc����������heap->element = (int *) (heap +1)
						//�ڶ��֣���malloc �ṹ�壬Ȼ��heap->elemetn = malloc
	//elemType element[]; //�������飬����һ��malloc���,,,����ֻ��heap->ellent[n]
};

pPriorityQueue initPriorityQueue(int capacity);
void Destroy(pPriorityQueue heap);

void insertPriorityQueue(pPriorityQueue heap, elemType elem);

elemType  deleteMinElem(pPriorityQueue heap);

elemType findMaxElem(pPriorityQueue heap);

bool isFull(pPriorityQueue heap);

bool isEmpty(pPriorityQueue heap);

void  travelPriorityQueue(pPriorityQueue heap);
#endif
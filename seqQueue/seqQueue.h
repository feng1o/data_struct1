#ifndef  _SEQQUEUE_H
#define  _SEQQUEUE_H

#include "iostream"
#include "string"

using namespace  std;
class CMyQueue
{
public:
	CMyQueue() = default;
	CMyQueue(int cap) ;
	virtual ~CMyQueue();

	void clearQueue();
	//void destroyQueue();
	bool isEmpty() const;
	bool isFull() const;
	int  getLength() const;
	bool insertElement(int elem);
	bool deleteElement(int &elem);
	void travelQueue();


private:
	const int m_iQueueCapacity;
	int m_iQueueLength;
	int *m_pQueue;
	int m_iQueueHeader;
	int m_iQueueTail;
};
#endif
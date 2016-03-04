#include "seqQueue.h"
#include "vector"
#include "iterator"
#include "array"
CMyQueue::CMyQueue(int cap) :m_iQueueCapacity(cap)
{
	//m_iQueueCapacity = cap; //如果是const的成员变量，这样是挫的，必须列表直接初始化
	m_pQueue = new int[m_iQueueCapacity];
	if (!m_pQueue)
		perror("heap erorr");
	clearQueue();
	/*m_iQueueHeader = 0;
	m_iQueueTail = 0;
	m_iQueueLength = 0;*/
}

CMyQueue::~CMyQueue(){  //析构函数一断声明，必须定义
	delete[] m_pQueue;
}

void CMyQueue::clearQueue(){
	m_iQueueHeader = 0;
	m_iQueueTail = 0;
	m_iQueueLength = 0;
}

bool CMyQueue::isEmpty() const{
	return !m_iQueueLength ? true : false;
}

bool CMyQueue::isFull() const{
	return m_iQueueLength == m_iQueueCapacity ? true : false;
}

int CMyQueue::getLength() const {
	return m_iQueueLength;
}
bool CMyQueue::deleteElement(int &elem) //elem返回，必须是引用 
{
	if (!isEmpty()){
		elem = m_pQueue[m_iQueueHeader];
		m_iQueueHeader = ++m_iQueueHeader % m_iQueueCapacity;
		m_iQueueLength--;
		cout << "delete elem:" << elem << endl;
		return true;
	}
	else{
		fprintf(stdout, "empty no delete\n");
		return false;
	}
	
	
}

bool CMyQueue::insertElement(int elem){ //enqueue
	if (!isFull()){
		m_pQueue[m_iQueueTail] = elem;
		m_iQueueTail = ++m_iQueueTail % m_iQueueCapacity;
		++m_iQueueLength;
		return true;
	}
	else{
		perror("fulle no inser\n");
		return false;
	}

}

void CMyQueue::travelQueue(){
	for (int i = m_iQueueHeader; i < m_iQueueLength+m_iQueueHeader;i++){
		cout << m_pQueue[i%m_iQueueCapacity] << endl;
	}
}

				const string& fun()
				{
					int i = 0;
					return "dakg";  //返回局部变量的 指针 引用均是error的  
				}

void main()
{
	CMyQueue cQueue(2);
//	CMyQueue cQueue2;
	cout << "is empty:" << cQueue.isEmpty()<<endl;
	int elem;
	cQueue.deleteElement(elem);
	cQueue.insertElement(0);
	cQueue.insertElement(1);
	cQueue.insertElement(2);
	cQueue.travelQueue();
	cQueue.deleteElement(elem);
	cQueue.deleteElement(elem);
	cQueue.insertElement(3);
	cout << "length :"<<cQueue.getLength() << endl;
	cQueue.insertElement(4);
	cQueue.travelQueue();


#if 0
	//const string str = fun();  //返回局部变量的 指针 引用均是error的  
	//cout << "fun :" << fun();
	vector<int> a{ 12, 32, 53 };
	for (int i = 0; i < a.size(); i++){
		int j = *std::next(a.begin());
		cout << "I :" << j << endl;
	}

	array<int, 2> a1{ { 1, 2 } }; //初始化方法
	for (auto &i : a1)
		cout << "aa:" << i << endl;
#endif
	
}
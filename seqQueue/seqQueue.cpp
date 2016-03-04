#include "seqQueue.h"
#include "vector"
#include "iterator"
#include "array"
CMyQueue::CMyQueue(int cap) :m_iQueueCapacity(cap)
{
	//m_iQueueCapacity = cap; //�����const�ĳ�Ա�����������Ǵ�ģ������б�ֱ�ӳ�ʼ��
	m_pQueue = new int[m_iQueueCapacity];
	if (!m_pQueue)
		perror("heap erorr");
	clearQueue();
	/*m_iQueueHeader = 0;
	m_iQueueTail = 0;
	m_iQueueLength = 0;*/
}

CMyQueue::~CMyQueue(){  //��������һ�����������붨��
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
bool CMyQueue::deleteElement(int &elem) //elem���أ����������� 
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
					return "dakg";  //���ؾֲ������� ָ�� ���þ���error��  
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
	//const string str = fun();  //���ؾֲ������� ָ�� ���þ���error��  
	//cout << "fun :" << fun();
	vector<int> a{ 12, 32, 53 };
	for (int i = 0; i < a.size(); i++){
		int j = *std::next(a.begin());
		cout << "I :" << j << endl;
	}

	array<int, 2> a1{ { 1, 2 } }; //��ʼ������
	for (auto &i : a1)
		cout << "aa:" << i << endl;
#endif
	
}
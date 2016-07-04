
//http://kelvinh.github.io/blog/2014/04/19/research-on-operator-new-and-delete/
/************************************************************************/
*�ص�see����������������                                                                     */
/************************************************************************/

#include <iostream>
#include "string"
using namespace std;

class C {
public:
	C(int i=0) : i(i) {
		cout << "C constructor." << endl;
	}

	~C() {
		cout << "C destructor." << endl;
	}

	// �˴�����Ϊstatic��non-static���ɣ���ͬ
	/* static */ 
	void *operator new(size_t size, void *p, const string& str){
		cout << "In our own operator new." << endl;
		cout << str << endl;
		if (!p) {
			cout << "Hey man, are you aware what you are doing?" << endl;
			return ::operator new(size);//ȫ�ֵ�new����std��
		}
		return p;
	}

	void* operator new (size_t size, const string& str){
		cout << "my new with no  p........\n" << size << endl;
		return malloc(size);
	}
		//ostream& operator << (ostream& cou, const string & str){ //�����ж�Ĳ�����
		//��Ϊcout�������������Ĳ�����������Ϊ��Ԫ�����ǿ����ڣ��������ģ������Ĭ���౾�¾���һ��
		ostream& operator << (ostream& cou){
		cou << "���������������������Ϊ����ĳ�Ա���������Իᵼ�º�������ʽ��ͬ\n";
		cou << "i=" << i << " ...n=" << n << endl;
		return cou;
	}

		/* static */ void operator delete(void *p) {
		cout << "We should do nothing in operator delete." << endl;
		// ���ȡ����һ�е�ע�ͣ��������ִ��ʱcrash
		// ::operator delete(p);
	}

	void f() {
		cout << "hello object, i: " << i << endl;
	}

private:
	int i;
	int n;
	//int n2;
};

int main() {
	char buf[sizeof(C)];
	C *pc = new (buf, "Yeah, I'm crazy!") C(1024);//C�ǵ�һ��������
	pc->f();

	std::cout << "..........................\n";
	C* pc2 = new (0, "a")C;  //0�ǵڶ�������������һ��������C��
	// �˴�ԭ����Ӧ�õ���delete����Ӧ��ֻ��ʽ������������������Ϊ�������ص�operator delete������ʲô�����������ǰ�ȫ��
	delete pc;

	cout << "\nno point .....................\n";
	void *p = new("void")C;// ��һ��������c,����󣬣����ĸ����void�ˣ�����������ľ���

	cout << "...........�����������....\n";
	*pc2 << cout;
	return 0;
}

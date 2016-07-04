
//http://kelvinh.github.io/blog/2014/04/19/research-on-operator-new-and-delete/
/************************************************************************/
*重点see。。。。。。。。                                                                     */
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

	// 此处声明为static或non-static均可，下同
	/* static */ 
	void *operator new(size_t size, void *p, const string& str){
		cout << "In our own operator new." << endl;
		cout << str << endl;
		if (!p) {
			cout << "Hey man, are you aware what you are doing?" << endl;
			return ::operator new(size);//全局的new，，std的
		}
		return p;
	}

	void* operator new (size_t size, const string& str){
		cout << "my new with no  p........\n" << size << endl;
		return malloc(size);
	}
		//ostream& operator << (ostream& cou, const string & str){ //不能有多的参数，
		//因为cout就是两个参数的操作符，，作为友元函数是可以在（）两个的，这里会默认类本事就是一个
		ostream& operator << (ostream& cou){
		cou << "重载了输出运算符，这个作为了类的成员函数，所以会导致和正常形式不同\n";
		cou << "i=" << i << " ...n=" << n << endl;
		return cou;
	}

		/* static */ void operator delete(void *p) {
		cout << "We should do nothing in operator delete." << endl;
		// 如果取消下一行的注释，程序会在执行时crash
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
	C *pc = new (buf, "Yeah, I'm crazy!") C(1024);//C是第一个操作数
	pc->f();

	std::cout << "..........................\n";
	C* pc2 = new (0, "a")C;  //0是第二个参数，，第一个参数是C？
	// 此处原本不应该调用delete，而应该只显式调用析构函数，但因为我们重载的operator delete并不做什么操作，所以是安全的
	delete pc;

	cout << "\nno point .....................\n";
	void *p = new("void")C;// 第一个参数是c,类对象，，，的哥就是void了，，（）里面的就是

	cout << "...........重载输出测试....\n";
	*pc2 << cout;
	return 0;
}

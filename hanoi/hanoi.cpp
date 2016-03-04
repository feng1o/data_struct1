#if 0
#include "iostream"
#include "string"

class hanoi
{
public:
	hanoi(int n)  : num(n)  {};
	~hanoi();
	void hanoiMove(int num, char a, char b, char c) ;
	int get()
	{return num;}
private:
	int num;

};


hanoi::~hanoi()
{
}

void hanoi::hanoiMove(int n, char a, char b, char c) 
{
	if (n>0)
	{
		if (1 == n)
		{
			std::cout << "move " << a << " to " << c << std::endl;
		}
		else
		{
			hanoiMove(n - 1, a, c, b);
			std::cout << "move " << a << " to " << c << std::endl;
			hanoiMove(n - 1, b, a, c); //回复到初试太了，，，
		}

	}
}
struct xx{
	int a;
	int *p1;
	std::string str;
	char *ch;
};
int main()
{
	int num = 2;
	struct xx  a0{ 3, &num, "str", "x" }; //初始化方式区别，，
	struct xx *a1 = new struct xx;

	//*a1 = a0; //a1 = &a0;区别
	a1->a= 2; //(*a1).a = 2区别；
	a1->p1 = &num; //此处必须是 地址，struct里面存的是一个char字符串的地址，并不是一个字符串string，
	//a1->ch = 'a'; //错误的，，，ch是指针，不是char一个字符
	a1->ch = "a";
	a1->str = "xx";
	std::cout << a1->a << std::endl;  //有无*对去向符号有影响
	std::cout << a1->p1 << std::endl; //地址，而不是值
	std::cout << *a1->p1 << std::endl; //值

		struct xx * *px; //二级指针的，，，，，，，，，，，，，，，，，，，，，，，，
		px = new struct xx *; //理解这个很重要，，为什么要他，，，，
		*px = new struct xx;  //然后继续new呢？？？
		(*px)->a = 200;      //这里的*为什么不可少呢？
		std::cout << "\n" << (*px)->a << std::endl; //同理*号

	hanoi hanoi1(3);
	int n = hanoi1.get();
	hanoi1.hanoiMove(n, 'a', 'b', 'c');
}
#endif
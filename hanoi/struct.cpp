#if 0
#include "iostream"
#include "string"

struct xx{
	int a;
	int *p1;
	std::string str;
	char *ch;
};
int main()
{
	int num = 2;
	struct xx  a0{ 3, &num, "str", "x" }; //��ʼ����ʽ���𣬣�
	struct xx *a1 = new struct xx;

	//*a1 = a0; //a1 = &a0;����
	a1->a = 2; //(*a1).a = 2����
	a1->p1 = &num; //�˴������� ��ַ��struct��������һ��char�ַ����ĵ�ַ��������һ���ַ���string��
	//a1->ch = 'a'; //����ģ�����ch��ָ�룬����charһ���ַ�
	a1->ch = "a";
	a1->str = "xx";
	std::cout << a1->a << std::endl;  //����*��ȥ�������Ӱ��
	std::cout << a1->p1 << std::endl; //��ַ��������ֵ
	std::cout << *a1->p1 << std::endl; //ֵ

	struct xx * *px; //����ָ��ģ�����������������������������������������������
	px = new struct xx *; //����������Ҫ����ΪʲôҪ����������
	*px = new struct xx;  //Ȼ�����new�أ�����
	(*px)->a = 200;      //�����*Ϊʲô�������أ�
	std::cout << "\n" << (*px)->a << std::endl; //ͬ��*��

}
#endif
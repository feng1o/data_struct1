#define  _CRT_SECURE_NO_WARNINGS
/*
格式化输入输出问题。。。。。。
*/
#include "stdlib.h"
#include "windows.h"
#include "stdio.h"

#if 0
int main()
{
	system("color 1E");
	int num;
	num = 10;
	char str[50];
	char * cstr = (char *)malloc(sizeof(char)*100);
	//char * cstr = nullptr;//error
	sprintf(str, "for /1 %%i in  （1,1，%d) do echo china", num);
	system(str);

	int n;
	printf("%10.3f\n", 10.01);
	printf("%C\n", 'a');
	puts("puts自动换行");
	//gets(str);
	gets(cstr);

	puts(cstr);
	system("pause");
}
#endif


int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{

#ifdef _cplusplus
	printf("c++\n");
#else
	printf("c\n");
#endif // _cplusplus

	int a = 0,b =0, c = 0;
	scanf("%d%*d%d", &a, &b, &c);	
	printf("%d,%d,%d\n", a, b, c);

	scanf("%3d%3d%3d", &a, &b, &c);
	printf("%d,%d,%d\n", a, b, c);
	long long ll;
	float fn;
	scanf("%d", &ll);
	scanf("%3.2f", &fn);//错误的，，，不能格式化控制进度输入
	printf("%ld", ll);

	double df=0.01;
	scanf("%f", &df);//f不能获取，，，结果还是0.01
	scanf("%lf", &df);
	printf("%lf", df);
	FILE *file="text.txt";

}
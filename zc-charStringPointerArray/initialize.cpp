/*
*初始化问题汇总：
*/
#define  _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"

#define  def_connect(i)  printf("a"#i);
void main1()
{
		int a2[10][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		int *a[3];
		a[0] = a2[0];
		a[1] = a2[1];
		a[2] = a2[2];
		//或者
		a[0] = (int*)malloc(sizeof(int) * 3);
	//	a[0] = { 1, 2, 3 };//error
		int i = 0, j = 0;
		for (; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("a[%d][%d}=%d\n", i, j, a[i][j]);
			}
		}
		printf("\n%d\n\n", *(*a + 1));
}
//结构体初始化 位域操作
void main()
{
	struct _tagStruct1
	{
		int a = 1;
		int b = 2;
	} istr1;
//	istr1.a = 2;
	printf("结构体=%d\n", istr1.a);

	struct _tagStruct2
	{
		int a : 1;
		int b : 2;
	} istr2;
	istr2.a = 1;
	printf("结构体=%d\n", istr2.a);

	typedef struct  AA
	{
		unsigned char b1 : 5;
		unsigned char b2 : 5;
		unsigned char b3 : 5;
		unsigned char b4 : 5;
		unsigned char b5 : 5;
	}AA1;
	struct test1
	{
		char a : 1;
		char : 2;
		long b : 3;
		char c : 2;
	}AA;//12

	printf("daxiao = %d",sizeof(AA));//　但实际上只用了25位，即4个字节，

	int number = 12345;
	char string[25];

	_itoa(number, string, 2);
	printf("integer = %d string = %s\n", number, string);
	def_connect(2);
}
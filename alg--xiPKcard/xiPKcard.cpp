extern "C"{
#define  _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

#define  def_Num 52
#define  def_SIZE(a)  sizeof((a))/sizeof((a[0]))  
#define  def_swap(a, b) a^=b^=a^=b
#define  def_swap_memory(a,b) do \
	{\
		int x=2;int *tmp=&x;memcpy(tmp,&(a),sizeof(a));\
		memcpy(&(a), &(b), sizeof(a));memcpy(&b, tmp,sizeof(b));\
	} while (0)
	void printCard(int a[], int N)
	{
		int a_size = 0;
		int a_size2 = def_SIZE(a);  //这里等于是指针了，不是数组了！！！！
		printf("sizeof a =%d\n", sizeof(a));   //这个size为0000！！！！！
		printf("def_size2 =%d\n", a_size2);   //这个size为0000！！！！！
		while (a_size < N)
		{
			printf("%4d", a[a_size++]);
			if ((a_size) % 13 == 0)
				printf("\n");
		}
	}

	/*
	*思想：
	*为了防止每次生成随机数还要判定重复，这里
	*先生成一个有序的，然后在随机生成这个范围树，然后和原有序的交换位置就是了
	*/
	void XiPKcard(int a[], int num)
	{
		int i;
		for (i = 0; i <= num - 1; i++)
			a[i] = i + 1;
		//printf("xxxx\n");
		printCard(a, num);
		time_t tim;
		time(&tim);
		printf("time = %s", ctime(&tim));
		struct tm *stTime = localtime(&tim);
		printf("time tm = %s\n", asctime(stTime));

		srand(tim);
		for (i = 0; i < num; i++)
		{
			int k = rand() % num + 1;
			def_swap_memory(a[i], a[k]);
			//def_swap(a[i], a[k]);
		}
		printCard(a, num);
	}



	int main()
	{
		//const int *ab = 2; //c++里面不可，，c里面可以
		//可这样
		int *ax = new int;
		*ax = 2;

		int a[def_Num] = { 0 };
		XiPKcard(a, def_Num);
		return 0;
	}

}
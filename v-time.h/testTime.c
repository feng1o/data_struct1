#define  _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

int main()
{
	//clock获取时间差 滴答
	clock_t start = clock();
	int i = 0;
	for (; i < 100000;i++){
		int *num = (int*) calloc(10000, sizeof(int));
		free(num);
	}
	clock_t end = clock();
	printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	//time_t获取的时间秒
	time_t time1;
	time1 = time(NULL);  // NULL就返回从
	Sleep(1000);
	time_t time2;
	time(&time2);   //两种方式
	int secods = difftime(time2,time1);
	printf("日历时间是long整形的=%ld\n", time1);
	printf("通过ctime转time_t==%s\n", ctime(&time1));  //ctime(time_t &)就是转日历时间到字符串
	printf("时间差=%d\n", secods);

	//将日历时间转化为世界标准时间（即格林尼治时间），并返回一个tm结构体来保存这个时间
	struct tm *structTime1, *structTime2;
	structTime1 = localtime(&time2);
	structTime2 = gmtime(&time2);
	printf("tm结构为 =%d, %d, %d\n", structTime2->tm_hour, structTime2->tm_isdst, structTime2->tm_mday);
	printf("通过asctime转time_t==%s\n", asctime(structTime1));  //asctime(time_t &)就是转tm到字符串
	printf("通过asctime转time_2==%s\n", asctime(structTime2));  //asctime(time_t &)就是转tm到字符串

	return 0;
}
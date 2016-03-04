#define  _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

int main()
{
	//clock��ȡʱ��� �δ�
	clock_t start = clock();
	int i = 0;
	for (; i < 100000;i++){
		int *num = (int*) calloc(10000, sizeof(int));
		free(num);
	}
	clock_t end = clock();
	printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	//time_t��ȡ��ʱ����
	time_t time1;
	time1 = time(NULL);  // NULL�ͷ��ش�
	Sleep(1000);
	time_t time2;
	time(&time2);   //���ַ�ʽ
	int secods = difftime(time2,time1);
	printf("����ʱ����long���ε�=%ld\n", time1);
	printf("ͨ��ctimeתtime_t==%s\n", ctime(&time1));  //ctime(time_t &)����ת����ʱ�䵽�ַ���
	printf("ʱ���=%d\n", secods);

	//������ʱ��ת��Ϊ�����׼ʱ�䣨����������ʱ�䣩��������һ��tm�ṹ�����������ʱ��
	struct tm *structTime1, *structTime2;
	structTime1 = localtime(&time2);
	structTime2 = gmtime(&time2);
	printf("tm�ṹΪ =%d, %d, %d\n", structTime2->tm_hour, structTime2->tm_isdst, structTime2->tm_mday);
	printf("ͨ��asctimeתtime_t==%s\n", asctime(structTime1));  //asctime(time_t &)����תtm���ַ���
	printf("ͨ��asctimeתtime_2==%s\n", asctime(structTime2));  //asctime(time_t &)����תtm���ַ���

	return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

/*
去掉头尾的空格，字符串处理，，，，问题
*/
#if 0
int main()
{
	int count = 0;
	int i = 0, j = 0;
	char *p = "  abcdadfaksj   ";
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}
	while (isspace(p[j]) && j >= 0)
	{
		j--;
	}

	count = j - i + 1;
	printf("str == %d", count);
	for (int k = 0; k <= count;k++)
	{
		printf("%c", *(p+k));
	}
	system("pause");
}
#endif



int trimSpace(char *p2)
{
	int count = 0;
	int i = 0, j = 0;
	const char *p = "  abcdadfaksj   ";
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}
	while (isspace(p[j]) && j >= 0)
	{
		j--;
	}

	count = j - i + 1;
	return count;

}

int main1()
{
	int a2[10][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int *a[3] ;
	/*

int *p[3];
for(i=0; i<3; ++i)
{
p[i] = (int *)malloc( sizeof(int));
}
	for (i = 0; i < 3; ++i)
	{
		free(p[i]);
	}
	不然怎么样呢？ 这样比较好：
		int arr[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int *pa[3];
	for (int i = 0; i < 3; ++i) {
		pa[i] = arr[i];
	}
	而 int *p[3] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };  是不行的！Warning一堆。
		*/
	a[0] = a2[0];
	a[1] = a2[1];
	a[2] = a2[2];
	int i = 0, j = 0;
	for (; i < 3;i++)
	{
		for (j = 0; j < 3;j++)
		{
			printf("a[%d][%d}=%d\n", i, j, a[i][j]);
		}
	}
	printf("\n%d\n\n", *(*a + 1));
	printf("chang=%d\n", trimSpace("abncd"));
	system("pause");
	return 0;
}
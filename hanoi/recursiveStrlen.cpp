#if 0
#include "stdlib.h"
#include "stdio.h"
#define  defMyPrint(x)  printf("%s长度是%d",#x,x)
int MyStrLen(const char * str)
{
	if (str == nullptr)
	{
		return -1;
	}
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return MyStrLen(str + 1) + 1;
	}
}

void main()
{
	int len = MyStrLen("abcd");
	printf("长度是%d\n", len);
	defMyPrint(len);
}
#endif
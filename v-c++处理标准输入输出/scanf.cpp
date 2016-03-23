#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

int main()
{
	char* str = (char*) calloc(1,sizeof(char));  //±ØÐënew£¬£¬£¬£¬
	scanf("%s", str);
	printf("sss = %s", str);

	char ch;
	scanf("%s", &ch);
	printf("sss = %c\n", ch);
	return 0;
}

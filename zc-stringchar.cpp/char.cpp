#if 0
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//×Ö·û´®·­×ª
void main()
{
	char c;
	//char *str = "abcdefg";
	char str[] = "abcdefg";
	int len = strlen(str);
	char *p1 = str;
	char *p2 = str + len - 1;

	while (p1 < p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;
	}

	printf("str:%s\n", str);

	system("pause");
}
#endif

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


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
	printf("str == %s", count);
	system("pause");
}
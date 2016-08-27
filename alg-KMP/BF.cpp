#if 0
#include "iostream"

int BruteForece2(const char* str, const char* substr){
	int len = strlen(str);
	int sublen = strlen(substr);
	for (int i = 0; i < len; ++i)
	{
		int j = 0;
		if (str[i] == substr[j])
		{
			if ((strncmp(str+i, substr, sublen) == 0))
				return i;
		}
	}
	return -1;
}
int BruteForece(const char* str, const char* substr)
{
	unsigned char len = strlen(str);
	unsigned char sublen = strlen(substr);
	for (int i = 0, k = 0; i < len; i++)
	{
		if (str[i] == substr[k])
		{
			if (k == sublen - 1)
				return i;
			++k;
		}
		else
			k = 0;
	}
	return -1;
}

int main()
{
	int index = BruteForece2("sdffesadg", "fe");
	std::cout << index << std::endl;
	return 0;
}
#endif
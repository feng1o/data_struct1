#if 01
#include "iostream"

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
	int index = BruteForece("liufe2ng", "fe");
	std::cout << index << std::endl;
	return 0;
}
#endif
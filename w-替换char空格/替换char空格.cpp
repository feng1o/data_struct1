#include "iostream"
#include "string"
#include "cctype"
#include "cstdlib"


class Solution {
public:
	void replaceSpace(char *str, int length) {
		char* m_str = new char[length];//这句的重要性，，，，
		std::strcpy(m_str, str);//没有new，直接char* m_str = std::strcpy(m_str, str),错误的
		int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (!isspace(m_str[i]) && '\0' != m_str[i])
			{
				str[j++] = m_str[i];
			}
			else if (isspace(m_str[i]))
			{
				str[j++] = '%%';
				str[j++] = '2';
				str[j++] = '0';
			}
			else if ('\0' == m_str[i])
			{
				str[j++] = '\0';
			}
		}
	}
};
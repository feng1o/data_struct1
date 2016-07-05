#include "iostream"
using namespace std;

class Solution {
public:
	bool match3(char* str, char* pattern){
		if (*str == '\0' && *pattern == '\0')
			return true;
		if ('\0' == *str && *pattern != '\0')
			return false;
		if (*pattern == '.' && *str != '\0')
			return match3(str + 1, pattern + 1);
		if (*pattern == *str)
			return match3(str + 1, pattern + 1);
		if (*(pattern + 1) == '*'){
			if (*pattern == *str || *pattern == '.' && *str != '\0')
				return match3(str + 1, pattern + 2) || match3(str, pattern + 2) || match3(str + 1, pattern);
			else
				return match3(str, pattern + 2);
		}
		return false;
	}
	bool match(char* str, char* pattern)
	{
		if (nullptr == str || nullptr == pattern)
			return false;
		return match2(str, pattern);
	}

private:
	bool match2(char* str, char* pattern){
		if (*str == '\0' && '\0' == *pattern)
			return true;
		if (*str != '\0' && '\0' == *pattern)
			return false;
		//if (*str == *pattern || (*str != '\0' && *pattern == '.'))
		//	return match2(str + 1, pattern + 1);
		if (*(pattern + 1) == '*'){
			if (*str == *pattern || (*pattern == '.' && *str != '\0'))
				return match2(str + 1, pattern + 2) || match2(str, pattern + 2) || match2(str + 1, pattern);
			else
				return match2(str, pattern + 2);
		}
		if (*str == *pattern || (*str != '\0' && *pattern == '.'))
			return match2(str + 1, pattern + 1);
		return false;
	}
};

int main(){
	Solution s1;
	cout << s1.match("a", ".*");
	return 0;
}
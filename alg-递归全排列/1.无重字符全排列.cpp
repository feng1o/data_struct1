#if 0
#include <iostream>
#include <string>

using namespace std;
//ÎÞÖØ¸´µÄ¡¢¡¢abc
void permutation_diff(char* arr, int lhs, int rhs);
int main(){
	char str[] = "abc";
	permutation_diff(str, 0, 2);
	return 0;
}

void permutation_diff(char* arr, int lhs, int rhs){
	int len = strlen(arr);
	if(lhs < 0 || rhs >= strlen(arr) || arr == nullptr)
		return;
	if(lhs == rhs){
		cout << arr << endl;
		return;
	}
	int b = lhs;
	for (int i = b; i < len; ++i)
	{
		swap(arr[0], arr[i]);
		permutation_diff(arr, lhs+1, rhs);
		swap(arr[0], arr[i]);  //»Ö¸´...
	}
}
#endif

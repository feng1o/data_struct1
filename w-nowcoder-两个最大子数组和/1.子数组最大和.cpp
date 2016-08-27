#define  aa
#if defined(a)
#include "iostream"
#include "string"
#include "exception"

using namespace std;

int maxSubArr(int *a, int len);
int main(){

	int a[] = { 1, -2, 3, -2, 5, 3, -3, 4, -2 };
	cout << "max =" << maxSubArr(a, 9) << endl;
	return 0;
}

int maxSubArr(int *a, int len){
	try{
		if (a == nullptr || len < 1)
			throw exception("error");
	}
	catch (exception &e){
		throw;
	}
	int max = a[0];
	int curr = a[0];
	for (int i = 1; i < len; ++i)
	{
		curr = curr < 0 ? 0 : curr;
		curr += a[i];
		if (curr > max)
			max = curr;
	}
	return max;
}
#endif
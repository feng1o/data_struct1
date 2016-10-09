#if defined(aa)
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
		if (a == nullptr || len < 2)
			throw exception("error");
	}
	catch (exception &e){
		throw;
	}
	int result = a[0];
	int *rhs = new int[len]();
	int max = a[len-1];
	rhs[len - 1] = max;
	int curr = a[len-1];
	for (int i = len - 2; i >= 0; --i)
	{
		curr = curr < 0 ? 0 : curr;
		curr += a[i];
		if (curr > max)
			max = curr;
		rhs[i] = max;
	}

	max = a[0];
	curr = a[0];
	for (int i = 1; i < len - 1; ++i)
	{
		curr = curr < 0 ? 0 : curr;
		curr += a[i];
		cout << curr << endl;
		if (curr > max){
			max = curr;
		}
		cout << "max =" << max << endl;

		if (result < max + rhs[i + 1]){
			result = max + rhs[i + 1];
		}
	}
	return result;
}
#endif
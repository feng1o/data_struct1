#include<iostream>  
#include<stdio.h>  
#include<math.h>  

using namespace std;

void InsertSort(int *a, int Num)
{
	if (a == nullptr) return;
	for (int i = 1; i < Num; ++i)
	{
		int lhs = 0;
		int rhs = i - 1;
		int tmp = a[i];
		while (lhs <= rhs){
			int mid = (lhs + rhs) / 2;
			if (a[mid] >= tmp)
				rhs = mid - 1;
			else
				lhs = mid + 1;
		}
		int j = i;
		while (j >= lhs+1){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
	return;
}

#define Num 7   
int main() {
	int a[] = { 12, 32, 34, 22, 22, 41, 15, 23};
	InsertSort(a, Num);
	for (int i = 0; i < Num; i++)
		cout << a[i] << endl;
	return 0;
}

#include "sort.h"
#define  def_swap(a, b) do { int k = a; a = b; b =k ;\
					} while (0)
#if 0
void InsertSort(int array[], int N)
{
	for (int i = 1; i < N; ++i)
	{
		int tmp = array[i];
		for (int j = i; j > 0; --j)
		{
			if (array[j-1] > tmp)
			{
				array[j] = array[j - 1];
			}
			else{
				array[j] = tmp;

			}
		}
	}
}
#endif
#if 0
void InsertSort(int array[], int N)
{
	int tmp, i;
	for (int j = 1; j < N; ++j)
	{
		tmp = array[j];
		for (i = j; i > 0 && array[i-1] > tmp; --i)
		{
			array[i] = array[i - 1];
		}
		array[i] = tmp;
	}
}
#endif
#if 0

void InsertSort(int array[], int N){
	if (!array)
	{
		return;
	}
	for (int i = 1; i < N; ++i)
	{
		int tmp = array[i];
		for (int j = i - 1; j > 0;  --j)
		{
			if (array[j] > tmp)
			{
				array[j + 1] = array[j];
			}
			else{
				array[j + 1] = tmp;
				break;
			}
		}
		
	}
}
#endif
#if 0  //折半查找不对....
int find(int *array, int begin, int end, int tmp){
	while (begin < end){
		int mid = (end + begin) / 2;
		if (array[mid] > tmp)
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return end;
}
void InsertSort(int array[], int N){
	if (!array) return;
	for (int i = 1; i < N; ++i)
	{
		int tmp = array[i];
		int begin = 0;
		int nMove = find(array, begin, i,tmp);
		int j = i;
		while (j > nMove + 1 )
			array[j] = array[--j];
		array[nMove + 1] = tmp;
	}
}
#endif
void InsertSort(int numbers[],  int n)
{
	int middle = 0;
	for (int i = 1; i < n; i++)
	{
		int low = 0;
		int high = i - 1;
		int temp = numbers[i];
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (temp < numbers[middle])
				high = middle - 1;
			else
				low = middle + 1;
		}
		for (int k = i; k > middle; k--)
			numbers[k] = numbers[k - 1];
		numbers[low] = temp;   //此处用 numbers[high+1] = temp ;也可
	}
}
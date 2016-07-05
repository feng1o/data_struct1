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
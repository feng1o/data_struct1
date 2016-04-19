#include "sort.h"

#define  def_swap(type, a, b) { type tmp = (a); (a) = (b); (b) = tmp;}
void BubbleSort(int array[], int n)
{
	char flag = false;
	for (int i = 0; !flag && i < n; ++i)
	{
		flag = true;
		for (int j = 0; j < n - i -1 ; ++j)
		{
			if (array[j] >= array[j+1])
			{
				def_swap(int, array[j], array[j + 1]);
				flag = false;
			}
		}
	}
}

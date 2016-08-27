#include "sort.h"

#if 1
void shellSort(int array[], int n)
{
	int gap = n / 2;
	while (gap){
		for (int i = gap; i < n; ++i)  //�ͻأ���������1��
		{
			int tmp = array[i];
			int j;
			for (j = i; j >= gap&& array[j-gap] > tmp; j=j-gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		gap /= 2;
	}
}
#endif

#if 0
void shellSort(int array[], int n) //no use this
{
	int gap = n / 2;
	for (; gap >= 1; gap /= 2)
	{
		for (int i = 0; i < n; ++i)  //һ����ߵ�...һ��gap�Ͱ����е�gapֵ��һ��....
		{
			for (int j = i + gap; j < n; j += gap)
			{
				int tmp = array[j];
				int k = j -gap ;
				while (k >= 0 && array[k] > tmp)
				{
					array[k + gap] = array[k];
					k -= gap;
				}
				array[k+gap] = tmp;
			}
		}
	}
}

#endif 
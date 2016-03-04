#include "sort.h"
#include "creatArrPrinArr.h"
#define  def_swap(x, y) {(x)^=(y)^=(x)^=(y);}
void CreatHeap(int a[],const int N)
{
	if (NULL == a || N < 2)
	{
		return ;
	}
	int son = 1;
	int fathor = 0;
	//int *backA = a;
	for (; son < N; son++)
	{
		fathor = (son-1) / 2; //fathor node
		while (son >= 1 && a[fathor] > a[son]){
			def_swap(a[fathor], a[son]);
			son = fathor;
			fathor = (son-1) / 2;
		}
	}
	return ;
}

void HeapAdjust(int a[], int index, int size)
{
	int son ;
	int fathor = index;
	int tmp = a[index];
	for (son = index; son < size-1 ; fathor = son)
	{
		son = fathor * 2 + 1;
		if (a[son + 1] < a[son])
			son++;
		if (tmp < a[son])
			break;
		a[fathor] = a[son];
		
		//printSortedArr(a, def_N);

	}
	a[son] = tmp;
}
void  HeapSort(int *a, int N)
{
	CreatHeap(a, N);
	printSortedArr(a, def_N);
	int i;
	for (i=0; i < N;i++)
	{
		//int tmp = a[N - i];
		//a[N - i] = a[1];
		//a[1] = a[N - i];
		def_swap(a[0], a[N-1-i]);
		//CreatHeap(a, N - i-1);
		HeapAdjust(a, 0, N -1- i);
	}
	return  ;
}

#if 0
public class HeapSort {
	public void buildheap(int array[]){
		int length = array.length;
		int heapsize = length;
		int nonleaf = length / 2 - 1;
		for (int i = nonleaf; i >= 0; i--){
			heapify(array, i, heapsize);
		}
	}

	public void heapify(int array[], int i, int heapsize){
		int smallest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left<heapsize){
			if (array[i]>array[left]){
				smallest = left;
			}
			else smallest = i;
		}
		if (right<heapsize){
			if (array[smallest]>array[right]){
				smallest = right;
			}
		}
		if (smallest != i){
			int temp;
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			heapify(array, smallest, heapsize);
		}
	}

	public void heapsort(int array[]){
		int heapsize = array.length;
		buildheap(array);

		for (int i = 0; i < array.length - 1; i++){
			// swap the first and the last
			int temp;
			temp = array[0];
			array[0] = array[heapsize - 1];
			array[heapsize - 1] = temp;
			// heapify the array
			heapsize = heapsize - 1;
			heapify(array, 0, heapsize);

		}
	}
#endif
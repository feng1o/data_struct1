#include "sort.h"
#include "creatArrPrinArr.h"
#define  def_swap(x, y) {(x)^=(y)^=(x)^=(y);}
#define  SON
//#define  FATHER

#if defined(SON)
void CreatHeap(int a[],const int N)
{
	if (NULL == a || N < 2)
	{
		return ;
	}
	int son = 1;
	int fathor = 0;
	//int *backA = a;
	for (; son < N; ++son)
	{
		fathor = (son-1) / 2; //fathor node
		while (son >= 1 && a[fathor] > a[son]){
			def_swap(a[fathor], a[son]);   //这个可以改变下，移动，，然后插入
			son = fathor;
			fathor = (son-1) / 2;
		}
	}
	return ;
}
#endif

//这个是从父节点，到子节点一层层变化的，，，往下，上面的是往上搜，找
#ifdef FATHER
void CreatHeap(int a[], int i, const int N)
{
	if (a) return;
	int tmp ;
	while (i > 0 && i <= N/2)
	{
		int leftSon = 2 * i + 1;
		int miniSon;
		tmp = a[i];
		if (leftSon + 1 < N && a[leftSon] > a[leftSon + 1])
			miniSon = leftSon +  1;
		else
			miniSon = leftSon ;
		if (tmp > a[miniSon])
			a[i] = a[miniSon];
		//if (a[miniSon] < a[i]){
		//	def_swap(a[i], a[miniSon]);
		//	i = miniSon;
		//}
		else
			break;
	}
	a[i] = tmp;  //重点，，，这个类似于插入排序移动方法
}
#endif
void HeapAdjust(int a[], int index, int size)
{
	int son ;
	int fathor = index;
	int tmp = a[index];
	for (son = 2*fathor + 1; son+1 < size-1 ; son = 2*fathor + 1)
	{
		//son = fathor * 2 + 1; //加这里会越界
		if (a[son + 1] < a[son])
			son++;
		if (tmp <= a[son])
			break;
		a[fathor] = a[son];
		fathor = son;
		//printSortedArr(a, def_N);

	}
	a[son] = tmp;
}
void  HeapSort(int *a, int N)
{
	CreatHeap(a, N);
	printSortedArr(a, def_N);
	printf(".......................\n");
	int i;
	for (i=0; i < N; ++i)
	{
		//int tmp = a[N - i];
		//a[N - i] = a[1];
		//a[1] = a[N - i];
		def_swap(a[0], a[N-1-i]);
		//CreatHeap(a, N - i-1);
		HeapAdjust(a, 0, N -1- i);
		
	}
	return ;
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
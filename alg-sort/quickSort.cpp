#include "sort.h"

void qSort(int array[], int begin, int end);
void QuickSort(int array[], int N)
{
	qSort(array, 0, N - 1);
}
void qSort(int array[], int begin, int end){
	int key = array[begin];
	int lhs = begin+1;
	int rhs = end;
	if (begin < end){
		while (lhs < rhs){
			std::cout << "lhs=" << lhs << std::endl;			
			while (lhs <rhs && array[rhs] > key)
				--rhs;
			while (lhs < rhs && array[lhs] <= key)
				++lhs;

			std::swap(array[lhs], array[rhs]);
		}
		std::swap(array[begin], array[rhs]);
		qSort(array, begin, rhs-1);
		qSort(array, rhs+1, end);
	}
}
void qSort3(int array[], int begin, int end){
	int key = array[end];
	int lhs = begin;
	int rhs = end-1;
	if (begin <= end){
		while (lhs < rhs){
			std::cout << "lhs=" << lhs << std::endl;
			while (lhs < rhs && array[lhs] <= key)
				++lhs;
			while (lhs < rhs && array[rhs] > key)
				--rhs;
			std::swap(array[lhs], array[rhs]);
		}
		std::swap(array[begin], array[rhs]);
		qSort(array, begin, rhs);
		qSort(array, rhs+1, end);
	}
}
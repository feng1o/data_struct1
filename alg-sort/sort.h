#ifndef  _SORT_H
#define _SORT_H
#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "assert.h"
#include "iostream"
#include "memory"
#include "iomanip"
#include "time.h"

#define  def_N 5

	
	void SelectSort(int array[], int N);

	void QuickSort(int array[], int N);

	void  HeapSort(int *a, int N);

	void CreatHeap(const int a[], int N);
	void CreatHeap(int a[], int i, const int N);

	void InsertSort(int array[], int N);

	void BubbleSort(int array[], int n);

	void shellSort(int array[], int n);


#endif
#ifndef  _SORT2_H
#define _SORT2_H
#define  _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "assert.h"
#include "iostream"
#include "memory"
#include "iomanip"

#define  def_N  10
extern "C"
{
	int* creatRandomArray(const int  N);

	void printInitialArr(const int *array, int N);
	void printSortedArr(const int *array, int N);

	void printStartTime();
	void printEndTime();
}


#endif
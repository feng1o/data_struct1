/*
 静态库的调用方式，
 1.工程里面的link--input--依赖里面
 2.使用#pragma  comment(lib,"xx.lib")
*/
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"

void msg()
{
	MessageBoxA(0, "static", "lib", 0);
}

int add(int a, int b)
{
	return a + b;
}
/*
 ��̬��ĵ��÷�ʽ��
 1.���������link--input--��������
 2.ʹ��#pragma  comment(lib,"xx.lib")
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
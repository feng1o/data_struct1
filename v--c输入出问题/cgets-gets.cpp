#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "conio.h"
#include "string.h"

int main()
{
	char * ch;
	char arr[20];
	int i = 0;
	arr[0] = 18;  //����18��
	ch = _cgets(arr);
	//_gotoxy(2, 10);
	printf("..read %d characters =%s \n", arr[1], ch);  //ch�����ַ�������arr1���ص�ʵ�ʳ���
	while (i++ < 15){
		//textcolor(i);
	}
	
	return 0;
}
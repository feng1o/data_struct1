
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"

#if 0
void print(char *s);
void main(){
	char str[] = "Geneius";
	print(str);
}
void print(char *s){
	if (*s){
		//print(s + 1);//��++s������������Ҫ�ģ�������
		//print(s++);//�������ݹ�
		print( ++s);//== s=s+1;printf(s);���µݹ�printf�ı�
		printf("%c", *s);//��һ��*s ������G����e��������
	}
}

#endif


#if 0
void fun(char **p, int n)//���˵�ַ
{
	char b[6] = "abcde"; int i;
	for (i = 0, *p = b; i < n; i++)//�����pָ����b���ı���p��ַ�����Ǵ�����һ��ָ�룬�޷��ı�ʵ��ָ��
		(*p)[i] = b[i];//�ı���b��Ӧ��ֵַ���Ǵ�������a
}
void main()
{
	char a[6] = "ABCDE";
	fun((char**)&a, 5);
	printf("%s\n", a);//�ı�a��1.ʹ�ô���ַ���ı��Ӧֵ����2.ʹ�ô�����ָ�룬��һ����ַ��
}

#endif
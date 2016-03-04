
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
		//print(s + 1);//和++s的区别是听重要的，，，，
		//print(s++);//导致死递归
		print( ++s);//== s=s+1;printf(s);导致递归printf改变
		printf("%c", *s);//第一个*s 到底是G还是e？？？？
	}
}

#endif


#if 0
void fun(char **p, int n)//传了地址
{
	char b[6] = "abcde"; int i;
	for (i = 0, *p = b; i < n; i++)//这里把p指向了b，改变了p地址，但是传的是一级指针，无法改变实参指针
		(*p)[i] = b[i];//改变了b对应地址值，非传进来的a
}
void main()
{
	char a[6] = "ABCDE";
	fun((char**)&a, 5);
	printf("%s\n", a);//改变a：1.使用传地址，改变对应值，，2.使用传二级指针，改一级地址，
}

#endif
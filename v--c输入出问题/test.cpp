#if 0
#include "stdio.h"
#include "ctype.h"
#include "conio.h"

int main(){
	//no buffer 
	printf("........\n");
	char  ch;
	int i = 0;
	ch = _getche();  //û���� ֱ���������
	_putch(ch);

	ch = _getch();  //û���� ����ʾ�����
	_putch(ch);

	while ((ch = _getche()) != EOF && isdigit(ch)){
		//i = 10 * i + ch - 48;
		i++;
		if (ch != EOF)
		{
			_ungetch(ch);  //�˻ص����̣�����ungetc���˻ص������������ʱ��getch��getche�ſ��Ի�ȡ�������Ĳ���
			//printf("getch,getche == %c\n", _getch());
			printf("xxxx\n"); //һֱѭ������Ϊ�Ƴ���    getche�ֻ�ȡ��������
			if (i == 3)
			{
				break;
			}
		}
	}

	while ((ch = getchar()) != '\n')
		printf("111   ch == %c\n", ch);
	while ((ch = getchar()) != EOF)
		printf("ch == %c\n", ch);
	return 0;

}
#endif
#if 0
#include "stdio.h"
#include "ctype.h"
#include "conio.h"

int main(){
	//no buffer 
	printf("........\n");
	char  ch;
	int i = 0;
	ch = _getche();  //没缓冲 直接输出入了
	_putch(ch);

	ch = _getch();  //没缓冲 不显示输入的
	_putch(ch);

	while ((ch = _getche()) != EOF && isdigit(ch)){
		//i = 10 * i + ch - 48;
		i++;
		if (ch != EOF)
		{
			_ungetch(ch);  //退回到键盘，，，ungetc是退回到输入流，这个时候getch，getche才可以获取，其他的不行
			//printf("getch,getche == %c\n", _getch());
			printf("xxxx\n"); //一直循环，因为推出了    getche又获取，，，，
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
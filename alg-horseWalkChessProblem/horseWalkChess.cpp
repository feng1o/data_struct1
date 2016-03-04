/*
*tip：
*    1.如果使用return，注意，rerun后面代码还有无执行必要，否则，加入return就完全不一样，回溯中，一定要注意恢复状态
*    2.如果使用了指针，地址，注意要保持前一个的状态，即使在回溯中也是这样，比如本例中的 x1,y1及xy区别，，
*    3.考虑把2中的x1，y1全部使用x,y做，不再用x1,y1,看是否会变化
*    4.如果使用的递归里面用了中间变量，或者用了其他的函数改变了你的中间值，一定要记得在返回前获取前一个值
*    5.，
*/

#if 0
#include "stdio.h"
#include "time.h"
#include "windows.h"

#define  def_X 5
#define  def_Y 5
int recur = 0;
int chess[def_Y][def_X];
void print();
//知道到位置(x,y)下一个可走的位置
int nextXY(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if (*y + 2 <= def_Y - 1 && *x - 1 >= 0 && chess[*x - 1][*y + 2] == 0)
		{
			*y += 2;
			*x -= 1;
			return 1;
		}
		break;
	case 1:
		if (*y + 2 <= def_Y - 1 && *x + 1 <= def_X - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*y += 2;
			*x += 1;
			return 1;
		}
		break;
	case 2:
		if (*y + 1 <= def_Y - 1 && *x + 2 <= def_X - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*y += 1;
			*x += 2;
			return 1;
		}
		break;
	case 3:
		if (*y - 1 >= 0 && *x + 2 <= def_X - 1 && chess[*x + 2][*y - 1] == 0)
		{
			*y -= 1;
			*x += 2;
			return 1;
		}
		break;
	case 4:
		if (*y - 2 >= 0 && *x + 1 <= def_X - 1 && chess[*x + 1][*y - 2] == 0)
		{
			*y -= 2;
			*x += 1;
			return 1;
		}
		break;
	case 5:
		if (*y - 2 >= 0 && *x - 1 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*y -= 2;
			*x -= 1;
			return 1;
		}
		break;
	case 6:
		if (*y - 1 >= 0 && *x - 2 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*y -= 1;
			*x -= 2;
			return 1;
		}
		break;
	case 7:
		if (*y + 1 <= def_Y - 1 && *x - 2 >= 0 && chess[*x - 2][*y + 1] == 0)
		{
			*y += 1;
			*x -= 2;
			return 1;
		}
		break;
	default:return 0;
		break;
	}
	return 0;
}

//深度优先遍历棋盘
//tag记录走了多少步，棋盘赋值，如果是非递归，就不能用局部变量，，，只用静态或者全局变量
void TravleChessBoard(int x, int y, int tag)//回溯方法
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//初始位置，x,y不能修改，保存下来，，，
	chess[x][y] = tag;
	if (!tag)
	{
		printf("...........递归次数是%d.........\n",recur);
		//Sleep(1000);
	//	getchar();
		print();
	}
	if (def_X*def_Y == tag)
	{
		print();
		chess[x][y] = 0; //return前，必须保证回复上次的修改，，理解，，，，否则就不能继续找下去了，，
		return ;		//只要有return就找到第一条就停止了
		//return 1；//如果只想让程序找到一条路径，就停止，，加return 1就很好，同时，注意return前不要改变结构状态，保持满的
	}
	//找下一个可走的坐标（x1,y1） tag+1，，可走标记flag置1
	flag = nextXY(&x1, &y1, count);
	while (false==flag && count <=7) //一个一个位置扫，找到第一个可以继续的位置就开始，这个就没有优化了，，，，，
	{
		count++;
		flag = nextXY(&x1, &y1, count);
	}
	while(flag)
	{
		TravleChessBoard(x1, y1, tag + 1);
		{
			//return 1;//找到一次就停止，，如果没有return，这个就会扫描出所有的，，前面的return前恢复状态
		}
		//recur++; //这里如果没有前面return，程序走多少次就会记录多少次，多与回溯次数，正常的也记录
		//找下一个可走的坐标（x1,y1） tag+1，，可走标记flag置1
	    x1 = x;  //这个两个不可少，否则会导致错误步子，，！！！！！！！！！！！！！！！！！！！！
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);//返回x，y值是对，但是，这个函数是改变传入实参的，这样就导致x,y变化了，但是，前面下一步使用的是x1,y1这样就等于往回跑了，错误，，
		while (0 == flag && count < 7) //一个一个位置扫，找到第一个可以继续的位置就开始，这个就没有优化了，，，，，
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0==flag)//回溯了标志
	{
		recur++;//统计回溯的次数，是应该在这里，，
		chess[x][y] = 0;//不能走了，没走完，就返回上一步，回溯;;这里的对x是-1，y-1了
	}
	return ;//有无都一样，，，，理解，，return不会导致后面任何操作未执行，所以是ok的
}
//static int tag = 1;

int main()
{
	int i, j;

	clock_t start, end;
	start = clock();
	for (i = 0; i < def_X;i++)
	{
		for (j = 0; j < def_Y; j++)
		{
			chess[i][j] = 0;
		}
	}
	TravleChessBoard(2, 0, 1);
	{
		printf("ok\n");
	}	
	end = clock();
	printf("时间==%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("回溯次数为%d\n", recur);
	print();
}



void print()
{
	int i, j;
	for (i = 0; i < def_X;i++)
	{
		for (j = 0; j < def_Y;j++)
		{
			printf("%4d", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

#endif

/*
*tip：x1，y1全部使用x,y做，不再用x1,y1,看是否会变化
*    1.如果使用return，注意，rerun后面代码还有无执行必要，否则，加入return就完全不一样，回溯中，一定要注意恢复状态
*    2.如果使用了指针，地址，注意要保持前一个的状态，即使在回溯中也是这样，比如本例中的 x1,y1及xy区别，，
*    3.考虑把2中的x1，y1全部使用x,y做，不再用x1,y1,看是否会变化
*    4.如果使用的递归里面用了中间变量，或者用了其他的函数改变了你的中间值，一定要记得在返回前获取前一个值
*    
*/

#if 0
#include "stdio.h"
#include "time.h"
#include "windows.h"

#define  def_X 5
#define  def_Y 5
int recur = 0;
int chess[def_Y][def_X];
void print();
//知道到位置(x,y)下一个可走的位置
int nextXY(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if (*y + 2 <= def_Y - 1 && *x - 1 >= 0 && chess[*x - 1][*y + 2] == 0)
		{
			*y += 2;
			*x -= 1;
			return 1;
		}
		break;
	case 1:
		if (*y + 2 <= def_Y - 1 && *x + 1 <= def_X - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*y += 2;
			*x += 1;
			return 1;
		}
		break;
	case 2:
		if (*y + 1 <= def_Y - 1 && *x + 2 <= def_X - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*y += 1;
			*x += 2;
			return 1;
		}
		break;
	case 3:
		if (*y - 1 >= 0 && *x + 2 <= def_X - 1 && chess[*x + 2][*y - 1] == 0)
		{
			*y -= 1;
			*x += 2;
			return 1;
		}
		break;
	case 4:
		if (*y - 2 >= 0 && *x + 1 <= def_X - 1 && chess[*x + 1][*y - 2] == 0)
		{
			*y -= 2;
			*x += 1;
			return 1;
		}
		break;
	case 5:
		if (*y - 2 >= 0 && *x - 1 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*y -= 2;
			*x -= 1;
			return 1;
		}
		break;
	case 6:
		if (*y - 1 >= 0 && *x - 2 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*y -= 1;
			*x -= 2;
			return 1;
		}
		break;
	case 7:
		if (*y + 1 <= def_Y - 1 && *x - 2 >= 0 && chess[*x - 2][*y + 1] == 0)
		{
			*y += 1;
			*x -= 2;
			return 1;
		}
		break;
	default:return 0;
		break;
	}
	return 0;
}

//深度优先遍历棋盘
//tag记录走了多少步，棋盘赋值，如果是非递归，就不能用局部变量，，，只用静态或者全局变量
void TravleChessBoard(int x, int y, int tag)//回溯方法
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//初始位置，x,y不能修改，保存下来，，，
	chess[x][y] = tag;
	if (def_X*def_Y == tag)
	{
		print();
		chess[x][y] = 0; //return前，必须保证回复上次的修改，，理解，，，，否则就不能继续找下去了，，
		return;		//只要有return就找到第一条就停止了
		//如果只想让程序找到一条路径，就停止，，加return就很好，同时，注意return前不要改变结构状态，保持满的
	}
	//找下一个可走的坐标（x1,y1） tag+1，，可走标记flag置1
	flag = nextXY(&x1, &y1, count);
	while (false == flag && count <= 7) //一个一个位置扫，找到第一个可以继续的位置就开始，这个就没有优化了，，，，，
	{
		count++;
		flag = nextXY(&x1, &y1, count);
	}
	while (flag)
	{
		TravleChessBoard(x1, y1, tag + 1);
		{
			//return 1;
		}
		//recur++; //这里如果没有前面return，程序走多少次就会记录多少次，多与回溯次数，正常的也记录
		//找下一个可走的坐标（x1,y1） tag+1，，可走标记flag置1
		x1 = x;  //这个两个不可少，否则会导致错误步子，，！！！！！！！！！！！！！！！！！！！！
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);//返回x，y值是对，但是，这个函数是改变传入实参的，这样就导致x,y变化了，但是，前面下一步使用的是x1,y1这样就等于往回跑了，错误，，
		while (0 == flag && count < 7) //一个一个位置扫，找到第一个可以继续的位置就开始，这个就没有优化了，，，，，
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0 == flag)//回溯了标志
	{
		recur++;//统计回溯的次数，是应该在这里，，
		chess[x][y] = 0;//不能走了，没走完，就返回上一步，回溯;;这里的对x是-1，y-1了
	}
	return;//有无都一样，，，，理解，，return不会导致后面任何操作未执行，所以是ok的
}
//static int tag = 1;

int main()
{
	int i, j;

	clock_t start, end;
	start = clock();
	for (i = 0; i < def_X; i++)
	{
		for (j = 0; j < def_Y; j++)
		{
			chess[i][j] = 0;
		}
	}
	TravleChessBoard(2, 0, 1);
	{
		printf("ok\n");
	}
	end = clock();
	printf("时间==%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("回溯次数为%d\n", recur);
	print();
}



void print()
{
	int i, j;
	for (i = 0; i < def_X; i++)
	{
		for (j = 0; j < def_Y; j++)
		{
			printf("%4d", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

#endif
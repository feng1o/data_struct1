#if 01
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
int TravleChessBoard(int x, int y, int tag)//回溯方法
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//初始位置，x,y不能修改，保存下来，，，
	chess[x][y] = tag;
	if (!tag)
	{
		printf("...........递归次数是%d.........\n", recur);
		//Sleep(1000);
		//	getchar();
		print();
	}
	if (def_X*def_Y == tag)
	{
		//print();
		//return前，必须保证回复上次的修改，，理解，，，，否则就不能继续找下去了，，
		//这里没有return，
		return 1;		//找完了，也就是走了一圈，结束了，，打印棋盘
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
		if (TravleChessBoard(x1, y1, tag + 1))
		{
			return 1;
		}
		//recur++;//记录回溯次数不对，这个地方只要没有前面的return，走都少次递归都会最终过来的，，，
		//找下一个可走的坐标（x1,y1） tag+1，，可走标记flag置1
		x1 = x;
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);
		while (0 == flag && count < 7) //一个一个位置扫，找到第一个可以继续的位置就开始，这个就没有优化了，，，，，
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0 == flag)
	{
		recur++;
		chess[x][y] = 0;//不能走了，没走完，就返回上一步，回溯;;这里的对x是-1，y-1了
	}
	return 0;
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
	if (TravleChessBoard(2, 0, 1))
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
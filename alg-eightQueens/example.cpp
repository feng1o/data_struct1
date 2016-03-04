/************************************************
*FAQ: 如何做到回溯后还能还原。。
*找边界方法
*如何做到扫描了所有可能路径？走完后，又是如何继续开始，最终终止条件是什么？
*想办法只找一条路径就停止《《《《
*************************************************/


#if 01
#include <stdio.h>

#define N 8

typedef struct _tag_Pos
{
	int ios;
	int jos;
} Pos;

static char board[N + 2][N + 2];
static Pos pos[] = { { -1, -1 }, { -1, 0 }, { -1, 1 } };//初始化方法
static int count = 0;

void init()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < N + 2; i++)
	{
		board[0][i] = '#';
		board[N + 1][i] = '#';
		board[i][0] = '#';
		board[i][N + 1] = '#';
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void display()
{
	int i = 0;
	int j = 1;

	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < N + 2; j++)
		{
			printf("%c", board[i][j]);
		}

		printf("\n");
	}
}

int check(int i, int j)
{
	int ret = 1;
	int p = 0;
	for (int t = 0; t < N;t++)//检测当前行，这个是为了实现找一个，，，
	{
		if (board[i][t] == '*')
			return false;
	}
	for (p = 0; p < 3; p++)
	{
		int ni = i;
		int nj = j;

		while (ret && (board[ni][nj] != '#'))
		{
			ni = ni + pos[p].ios;
			nj = nj + pos[p].jos;

			ret = ret && (board[ni][nj] != '*');
		}
		if (!ret)
		{
			break;
		}
	}

	return ret;
}

void find(int i)
{
	int j = 0;

	if (i > N)
	{
		count++;

		printf("Solution: %d\n", count);

		display();
		return;//这个return还是会让程序找完所有的，，，
		//因为是if else结构，进入了if，就不会进入else，反之一样，所以他们内部加个return，不做return前的重置是没错的
		//getchar();
	}
	else
	{
		for (j = 1; j <= N; j++)
		{
			if (check(i, j))
			{
				board[i][j] = '*';

				find(i + 1);
				if (i<N) //找到一种后，最后的那个皇后不让取消，还是会打印，会把这个皇后当做不存在？？为什么？
					//因为check不会去检查当前行，所以找个点看不到的
				board[i][j] = ' ';
			}
		}
	}
}

int main()
{
	init();
	find(1);

	return 0;
}
#endif
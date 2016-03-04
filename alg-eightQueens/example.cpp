/************************************************
*FAQ: ����������ݺ��ܻ�ԭ����
*�ұ߽緽��
*�������ɨ�������п���·���������������μ�����ʼ��������ֹ������ʲô��
*��취ֻ��һ��·����ֹͣ��������
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
static Pos pos[] = { { -1, -1 }, { -1, 0 }, { -1, 1 } };//��ʼ������
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
	for (int t = 0; t < N;t++)//��⵱ǰ�У������Ϊ��ʵ����һ��������
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
		return;//���return���ǻ��ó����������еģ�����
		//��Ϊ��if else�ṹ��������if���Ͳ������else����֮һ�������������ڲ��Ӹ�return������returnǰ��������û���
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
				if (i<N) //�ҵ�һ�ֺ������Ǹ��ʺ���ȡ�������ǻ��ӡ���������ʺ��������ڣ���Ϊʲô��
					//��Ϊcheck����ȥ��鵱ǰ�У������Ҹ��㿴������
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
#if 01
#include "stdio.h"
#include "time.h"
#include "windows.h"

#define  def_X 5
#define  def_Y 5
int recur = 0;
int chess[def_Y][def_X];
void print();
//֪����λ��(x,y)��һ�����ߵ�λ��
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

//������ȱ�������
//tag��¼���˶��ٲ������̸�ֵ������Ƿǵݹ飬�Ͳ����þֲ�����������ֻ�þ�̬����ȫ�ֱ���
int TravleChessBoard(int x, int y, int tag)//���ݷ���
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//��ʼλ�ã�x,y�����޸ģ���������������
	chess[x][y] = tag;
	if (!tag)
	{
		printf("...........�ݹ������%d.........\n", recur);
		//Sleep(1000);
		//	getchar();
		print();
	}
	if (def_X*def_Y == tag)
	{
		//print();
		//returnǰ�����뱣֤�ظ��ϴε��޸ģ�����⣬����������Ͳ��ܼ�������ȥ�ˣ���
		//����û��return��
		return 1;		//�����ˣ�Ҳ��������һȦ�������ˣ�����ӡ����
	}
	//����һ�����ߵ����꣨x1,y1�� tag+1�������߱��flag��1
	flag = nextXY(&x1, &y1, count);
	while (false == flag && count <= 7) //һ��һ��λ��ɨ���ҵ���һ�����Լ�����λ�þͿ�ʼ�������û���Ż��ˣ���������
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
		//recur++;//��¼���ݴ������ԣ�����ط�ֻҪû��ǰ���return���߶��ٴεݹ鶼�����չ����ģ�����
		//����һ�����ߵ����꣨x1,y1�� tag+1�������߱��flag��1
		x1 = x;
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);
		while (0 == flag && count < 7) //һ��һ��λ��ɨ���ҵ���һ�����Լ�����λ�þͿ�ʼ�������û���Ż��ˣ���������
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0 == flag)
	{
		recur++;
		chess[x][y] = 0;//�������ˣ�û���꣬�ͷ�����һ��������;;����Ķ�x��-1��y-1��
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
	printf("ʱ��==%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("���ݴ���Ϊ%d\n", recur);
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
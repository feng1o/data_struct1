/*
*tip��
*    1.���ʹ��return��ע�⣬rerun������뻹����ִ�б�Ҫ�����򣬼���return����ȫ��һ���������У�һ��Ҫע��ָ�״̬
*    2.���ʹ����ָ�룬��ַ��ע��Ҫ����ǰһ����״̬����ʹ�ڻ�����Ҳ�����������籾���е� x1,y1��xy���𣬣�
*    3.���ǰ�2�е�x1��y1ȫ��ʹ��x,y����������x1,y1,���Ƿ��仯
*    4.���ʹ�õĵݹ����������м�������������������ĺ����ı�������м�ֵ��һ��Ҫ�ǵ��ڷ���ǰ��ȡǰһ��ֵ
*    5.��
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
void TravleChessBoard(int x, int y, int tag)//���ݷ���
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//��ʼλ�ã�x,y�����޸ģ���������������
	chess[x][y] = tag;
	if (!tag)
	{
		printf("...........�ݹ������%d.........\n",recur);
		//Sleep(1000);
	//	getchar();
		print();
	}
	if (def_X*def_Y == tag)
	{
		print();
		chess[x][y] = 0; //returnǰ�����뱣֤�ظ��ϴε��޸ģ�����⣬����������Ͳ��ܼ�������ȥ�ˣ���
		return ;		//ֻҪ��return���ҵ���һ����ֹͣ��
		//return 1��//���ֻ���ó����ҵ�һ��·������ֹͣ������return 1�ͺܺã�ͬʱ��ע��returnǰ��Ҫ�ı�ṹ״̬����������
	}
	//����һ�����ߵ����꣨x1,y1�� tag+1�������߱��flag��1
	flag = nextXY(&x1, &y1, count);
	while (false==flag && count <=7) //һ��һ��λ��ɨ���ҵ���һ�����Լ�����λ�þͿ�ʼ�������û���Ż��ˣ���������
	{
		count++;
		flag = nextXY(&x1, &y1, count);
	}
	while(flag)
	{
		TravleChessBoard(x1, y1, tag + 1);
		{
			//return 1;//�ҵ�һ�ξ�ֹͣ�������û��return������ͻ�ɨ������еģ���ǰ���returnǰ�ָ�״̬
		}
		//recur++; //�������û��ǰ��return�������߶��ٴξͻ��¼���ٴΣ�������ݴ�����������Ҳ��¼
		//����һ�����ߵ����꣨x1,y1�� tag+1�������߱��flag��1
	    x1 = x;  //������������٣�����ᵼ�´����ӣ�������������������������������������������
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);//����x��yֵ�Ƕԣ����ǣ���������Ǹı䴫��ʵ�εģ������͵���x,y�仯�ˣ����ǣ�ǰ����һ��ʹ�õ���x1,y1�����͵����������ˣ����󣬣�
		while (0 == flag && count < 7) //һ��һ��λ��ɨ���ҵ���һ�����Լ�����λ�þͿ�ʼ�������û���Ż��ˣ���������
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0==flag)//�����˱�־
	{
		recur++;//ͳ�ƻ��ݵĴ�������Ӧ���������
		chess[x][y] = 0;//�������ˣ�û���꣬�ͷ�����һ��������;;����Ķ�x��-1��y-1��
	}
	return ;//���޶�һ������������⣬��return���ᵼ�º����κβ���δִ�У�������ok��
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
	printf("ʱ��==%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("���ݴ���Ϊ%d\n", recur);
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
*tip��x1��y1ȫ��ʹ��x,y����������x1,y1,���Ƿ��仯
*    1.���ʹ��return��ע�⣬rerun������뻹����ִ�б�Ҫ�����򣬼���return����ȫ��һ���������У�һ��Ҫע��ָ�״̬
*    2.���ʹ����ָ�룬��ַ��ע��Ҫ����ǰһ����״̬����ʹ�ڻ�����Ҳ�����������籾���е� x1,y1��xy���𣬣�
*    3.���ǰ�2�е�x1��y1ȫ��ʹ��x,y����������x1,y1,���Ƿ��仯
*    4.���ʹ�õĵݹ����������м�������������������ĺ����ı�������м�ֵ��һ��Ҫ�ǵ��ڷ���ǰ��ȡǰһ��ֵ
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
void TravleChessBoard(int x, int y, int tag)//���ݷ���
{
	int flag = 0;
	int count = 0;
	int x1 = x, y1 = y;//��ʼλ�ã�x,y�����޸ģ���������������
	chess[x][y] = tag;
	if (def_X*def_Y == tag)
	{
		print();
		chess[x][y] = 0; //returnǰ�����뱣֤�ظ��ϴε��޸ģ�����⣬����������Ͳ��ܼ�������ȥ�ˣ���
		return;		//ֻҪ��return���ҵ���һ����ֹͣ��
		//���ֻ���ó����ҵ�һ��·������ֹͣ������return�ͺܺã�ͬʱ��ע��returnǰ��Ҫ�ı�ṹ״̬����������
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
		TravleChessBoard(x1, y1, tag + 1);
		{
			//return 1;
		}
		//recur++; //�������û��ǰ��return�������߶��ٴξͻ��¼���ٴΣ�������ݴ�����������Ҳ��¼
		//����һ�����ߵ����꣨x1,y1�� tag+1�������߱��flag��1
		x1 = x;  //������������٣�����ᵼ�´����ӣ�������������������������������������������
		y1 = y;
		count++;
		flag = nextXY(&x1, &y1, count);//����x��yֵ�Ƕԣ����ǣ���������Ǹı䴫��ʵ�εģ������͵���x,y�仯�ˣ����ǣ�ǰ����һ��ʹ�õ���x1,y1�����͵����������ˣ����󣬣�
		while (0 == flag && count < 7) //һ��һ��λ��ɨ���ҵ���һ�����Լ�����λ�þͿ�ʼ�������û���Ż��ˣ���������
		{
			count++;
			flag = nextXY(&x1, &y1, count);
		}
	}
	if (0 == flag)//�����˱�־
	{
		recur++;//ͳ�ƻ��ݵĴ�������Ӧ���������
		chess[x][y] = 0;//�������ˣ�û���꣬�ͷ�����һ��������;;����Ķ�x��-1��y-1��
	}
	return;//���޶�һ������������⣬��return���ᵼ�º����κβ���δִ�У�������ok��
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
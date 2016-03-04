//#include "stdio.h"
//#include "windows.h"
////#pragma  comment(lib,"����̬��.lib")
//
//void main()
//{
//	system("tasklist");
//	system("calc");
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int n;//��Ʒ����
double c;//��������
double v[100];//������Ʒ�ļ�ֵ
double w[100];//������Ʒ������
double cw = 0.0;//��ǰ��������
double cp = 0.0;//��ǰ��������Ʒ��ֵ
double bestp = 0.0;//��ǰ���ż�ֵ
double perp[100];//��λ��Ʒ��ֵ�����
int order[100];//��Ʒ���
int put[100];//�����Ƿ�װ��

//����λ��ֵ����
void knapsack()
{
	int i, j;
	int temporder = 0;
	double temp = 0.0;

	for (i = 1; i <= n; i++)
		perp[i] = v[i] / w[i];
	for (i = 1; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
			if (perp[i] < perp[j])//ð������perp[],order[],sortv[],sortw[]
			{
				temp = perp[i];
				perp[i] = perp[i];
				perp[j] = temp;

				temporder = order[i];
				order[i] = order[j];
				order[j] = temporder;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;

				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
	}
}

//���ݺ���
void backtrack(int i)
{
	double bound(int i);
	if (i > n)
	{
		bestp = cp;
		return;
	}
	if (cw + w[i] <= c)
	{
		cw += w[i];
		cp += v[i];
		put[i] = 1;
		backtrack(i + 1);
		cw -= w[i];
		cp -= v[i];
	}
	if (bound(i + 1) > bestp)//������������������
		backtrack(i + 1);
}

//�����Ͻ纯��
double bound(int i)
{
	double leftw = c - cw;
	double b = cp;
	while (i <= n&&w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b;

}


int main()
{
	int i;
	printf("��������Ʒ��������������");
	scanf("%d %lf", &n, &c);
	printf("��������Ʒ�������ͼ�ֵ��");
	for (i = 1; i <= n; i++)
	{
		printf("��%d����Ʒ��������", i);
		scanf("%lf", &w[i]);
		printf("��ֵ�ǣ�");
		scanf("%lf", &v[i]);
		order[i] = i;
	}
	knapsack();
	backtrack(1);
	printf("���м�ֵΪ��%lf\n", bestp);
	printf("��Ҫװ�����Ʒ����ǣ�");
	for (i = 1; i <= n; i++)
	{
		if (put[i] == 1)
			printf("%d ", order[i]);
	}
	return 0;
}
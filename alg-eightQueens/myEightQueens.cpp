#if 0
#include "iostream"
#include "string"
#include "windows.h"
#define  def_NumOfQueens 8
using std::cout;
using std::endl;
using std::cin;

char board[def_NumOfQueens][def_NumOfQueens];
typedef struct tag_move
{
	int m_ix;
	int m_iy;
} move;
static move mm[3] = { { -1, -1 }, { -1, 0 }, { -1, +1 } };//初始化方法

void InitBoard()
{
	for (int i = 0; i < def_NumOfQueens;i++)
	{
		for (int j = 0; j < def_NumOfQueens;j++)
		{
			board[i][j] = '.';
		}
	}
}

void PrintBoard()
{
	int i, j;
	for (i = 0; i < def_NumOfQueens; i++)
	{
		for (j = 0; j < def_NumOfQueens; j++)
		{
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
bool CheckPosition(int posx, int posy)
{
	int x = posx, y = posy;
	int flag = true;
	for (int n = 0; n < 3; n++)
	{
		//flag = true;
		while (flag && x + mm[n].m_ix >= 0 && y + mm[n].m_iy >= 0&& y + mm[n].m_iy < def_NumOfQueens)
		{
			x += mm[n].m_ix;
			y += mm[n].m_iy;
			if (board[x][y] == '8'){
				flag = false;
				break;
			}
		}
		if (flag==false)
		{
			break;
		}
	}
	return flag;
}
int CountRowPossible(int row)
{
	int count=0;//保存当前行可能的位置
	for (int j = 0; j < def_NumOfQueens; j++)
	{
		if (CheckPosition(row-1,j))
		{
			count++;
		}
		//for (int n = 0; n < 3; n++)
		//{
		//	if (row + mm[n].m_ix >= 0 && [row + mm[n].m_ix][j + mm[n].m_iy] == '.'&&j + mm[n].m_iy<def_NumOfQueens && j + mm[n].m_iy>=0)
		//}
	}
	return count;
}
void LayoutQueens(int row)
{
	if (row>def_NumOfQueens)
	{
		cout << "\n---------------------------------------------\n";//<<CheckPosition(1,1);
		//PrintBoard();
		//return;
	}
	else
	{
		//int rowChoices = CountRowPossible(row);
		for (int i = 0; i < def_NumOfQueens; i++)
		{
			if (CheckPosition(row - 1, i))
			{
				board[row - 1][i] = '8';
				LayoutQueens(row + 1);
				board[row - 1][i] = '.';
			}
		}
	}

}
int main()
{
	cout << "八皇后问题..........................\n";
	InitBoard();
	PrintBoard();
	//cout<<CountRowPossible(1);
	LayoutQueens(1);
	//char ch;
	//cin.get(ch);
	//cout.put(ch);
	return 0;
}
#endif
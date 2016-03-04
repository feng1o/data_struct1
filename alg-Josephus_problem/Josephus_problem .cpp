/*-------------------------------------------------------------------------
* Name:   约瑟夫问题
* Date:   2016.0.16
* Author: lf
* 
* 实现过程：1.循环的问题，主要考虑如何一直在这个圈里面循环扫描
           2.注意计数快慢
*------------------------------------------------------------------------*/
#include "josephus_problem.h"
cJosephusProblem::cJosephusProblem(int peopleNum,int killNum,int *piArray) 
	:m_iPeopleNum(peopleNum), m_KiillNum(killNum)
{
	piArray = new int[peopleNum];
	m_piArray = piArray;

	std::cout << "构造函数do--------------------------------------\n";
	std::cout << "初始化各个人的位置\n";
	for (int i = 0; i < m_iPeopleNum; i++)
	{
		m_piArray[i] = 0;
	}
	std::cout << m_iPeopleNum << "\n";
	std::cout << m_KiillNum << "\n";
	std::cout << "构造函数do--------------------------------------\n\n";
}

cJosephusProblem::~cJosephusProblem()
{
	std::cout << "xigou\n";
}

void cJosephusProblem::TravelJosephusCircle()
{
	//std::cout << "travel.........\n";
	for (int i = 0; i < m_iPeopleNum; i++)
	{
		printf("结果是 %d\r", m_piArray[i]);
		std::cout << "第 " <<std::internal<<std::setw(2) << i\ 
		<< " 个人报数是" << m_piArray[i] << "\r";//也可实现，不能有尾部的那个结束endl
	}
}

void cJosephusProblem::JosephusDeal()
{
	std::cout << "默认每个人序号为0，，，，遍历------------------------------\n";
	TravelJosephusCircle();
	int i_fast = 0;
	int i_slow = 0;
	int i_kilnum = 0;
	while (i_slow++ < m_iPeopleNum)  //lsow就是最后的位置，每次数到自杀树+1，所以他满了就结束了
	{
		while (1)
		{
			int i_realPosition = i_fast % m_iPeopleNum;//关键，实现了循环整个表很多次
			++i_fast;
			if (m_piArray[i_realPosition] == 0)//只有是初始化的值说明这个人还活着，，否则就已死了，跳过
			{
				++i_kilnum;
			}
			if (m_KiillNum ==i_kilnum)//计数到自杀树，就加1，，，退出内部循环
			{
				m_piArray[i_realPosition] = i_slow;
				i_kilnum = 0;
				break;
			}

		}
	}
	std::cout << "\n处理后每个人序号为，，，，遍历------------------------------\n";
	TravelJosephusCircle();
}

void cJosephusProblem::HowManySaved()
{
	std::cout << "你想救多少人？？？，输入整数范围：" << 0 << "--" << m_iPeopleNum << std::endl;
	int i_saveNum = -1;
	std::cin >> i_saveNum;
	for (int i = 0; i < m_iPeopleNum;i++)
	{
		if (m_piArray[i] > m_iPeopleNum-i_saveNum)//。。。。。
		{
			std::cout << "位置" << std::setw(2) << i << "可站\n";
		}
	}
}


int main()
{
	int *iArray=NULL;
	cJosephusProblem josephus1(53222, 3, iArray);
	josephus1.JosephusDeal();
	josephus1.HowManySaved();
	return 0;
}
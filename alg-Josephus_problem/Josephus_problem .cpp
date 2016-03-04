/*-------------------------------------------------------------------------
* Name:   Լɪ������
* Date:   2016.0.16
* Author: lf
* 
* ʵ�ֹ��̣�1.ѭ�������⣬��Ҫ�������һֱ�����Ȧ����ѭ��ɨ��
           2.ע���������
*------------------------------------------------------------------------*/
#include "josephus_problem.h"
cJosephusProblem::cJosephusProblem(int peopleNum,int killNum,int *piArray) 
	:m_iPeopleNum(peopleNum), m_KiillNum(killNum)
{
	piArray = new int[peopleNum];
	m_piArray = piArray;

	std::cout << "���캯��do--------------------------------------\n";
	std::cout << "��ʼ�������˵�λ��\n";
	for (int i = 0; i < m_iPeopleNum; i++)
	{
		m_piArray[i] = 0;
	}
	std::cout << m_iPeopleNum << "\n";
	std::cout << m_KiillNum << "\n";
	std::cout << "���캯��do--------------------------------------\n\n";
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
		printf("����� %d\r", m_piArray[i]);
		std::cout << "�� " <<std::internal<<std::setw(2) << i\ 
		<< " ���˱�����" << m_piArray[i] << "\r";//Ҳ��ʵ�֣�������β�����Ǹ�����endl
	}
}

void cJosephusProblem::JosephusDeal()
{
	std::cout << "Ĭ��ÿ�������Ϊ0������������------------------------------\n";
	TravelJosephusCircle();
	int i_fast = 0;
	int i_slow = 0;
	int i_kilnum = 0;
	while (i_slow++ < m_iPeopleNum)  //lsow��������λ�ã�ÿ��������ɱ��+1�����������˾ͽ�����
	{
		while (1)
		{
			int i_realPosition = i_fast % m_iPeopleNum;//�ؼ���ʵ����ѭ��������ܶ��
			++i_fast;
			if (m_piArray[i_realPosition] == 0)//ֻ���ǳ�ʼ����ֵ˵������˻����ţ�������������ˣ�����
			{
				++i_kilnum;
			}
			if (m_KiillNum ==i_kilnum)//��������ɱ�����ͼ�1�������˳��ڲ�ѭ��
			{
				m_piArray[i_realPosition] = i_slow;
				i_kilnum = 0;
				break;
			}

		}
	}
	std::cout << "\n�����ÿ�������Ϊ������������------------------------------\n";
	TravelJosephusCircle();
}

void cJosephusProblem::HowManySaved()
{
	std::cout << "����ȶ����ˣ�����������������Χ��" << 0 << "--" << m_iPeopleNum << std::endl;
	int i_saveNum = -1;
	std::cin >> i_saveNum;
	for (int i = 0; i < m_iPeopleNum;i++)
	{
		if (m_piArray[i] > m_iPeopleNum-i_saveNum)//����������
		{
			std::cout << "λ��" << std::setw(2) << i << "��վ\n";
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
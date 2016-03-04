#include "iostream"
#include "string"
#include "memory"
#include "iomanip"
class cJosephusProblem
{
public:
	cJosephusProblem(int peopleNum, int killNum, int *piArray);
	void JosephusDeal();
	void TravelJosephusCircle();
	void HowManySaved();
	~cJosephusProblem();

private:
	int m_iPeopleNum;
	int m_KiillNum;
	int *m_piArray;

};
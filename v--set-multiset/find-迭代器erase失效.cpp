/***********************************************************************
tip:find������Ԫ��֮��type���ͣ������ǵ��������Ͼ��Ѿ����ڲ��ܻ�ȡ��������
����find    
tip2: erase��ʱ�򣬱����������ӵ�һ��set��ȡ��iterator��Ȼ�����erase�����
����������ô�ȼ�����ʧЧ�ˣ���ʱ�����ɾ�Ͳ��ԣ������������ñ����ʱ֧�ݴ�
***********************************************************************/
#include "iostream"
#include "string"
#include "set"
using namespace std;
int main(){
	int *pint = new int[33]();
	cout << pint[0] << " " << pint[3] << endl;

	string str[] = { "abc", "cde", "efg", "ghj" }; //tip3:::: string *str��error�����ĵ�
	multiset<char> setend;
	multiset<char> setbegin;
	for (int i = 0; i < 4; ++i)
	{
		int len = str[i].size();
		cout << str[i][0] << "---end --" << str[i][len - 1] << endl;
		setend.insert(str[i][len - 1]);
		setbegin.insert(str[i][0]);
	}
				for (auto &it : setbegin)
				{
					cout << ".begin..." << it << endl;
				}
				cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				for (auto &it : setend)
				{
					cout << "end...." << it << endl;
				}
	int size = setbegin.size();
	auto it = setbegin.begin();
	decltype (it) it2;
	decltype (it) it3;
	for (int i = 0; i < size; ++i)
	{
		cout << "\n -----------------------it = " << *it << endl;
		cout << "find...............find....find: " << *setbegin.find(*it) << endl;
		if ((it3 = setend.find(*it)) != setend.end())
		{
			it2 = it;
			++it2;
			cout << "erase ...erarse...............erarset" << endl;
			setbegin.erase(*it);
			setend.erase(*it3);
			it = it2;
		}
		else
			++it;
		cout << ">....................................begin.............\n";
		for (auto &it2 : setbegin)
		{
			cout << "...." << it2 << endl;
		}
	}
	if (setbegin.size() == setend.size() && setbegin.size() <= 1)
	{
		cout << "ook\n";
	}
	else
		cout << "error\n";
	return 0;
}

#if 0
#include<iostream>
#include "string"

using namespace std;

void trial_divisio_fac(int n){
	int a = 2;
	while (a*a <= n){
		while (n%a == 0){
			cout << a << ' ';
			n = n / a;
		}
		a++;
	}
	if (n > 1) cout << n << ' ';
}
int main(){
	string str = "abcdefg";
	int len = str.size();
	int n = 2;

	string str1, str2;
	str1.insert(0, str, 0, n);
	cout << str1 << endl;
	str2.insert(0, str, n, len - n);
	str2 += str1;
	cout << str2 << endl;
	int n2;
	cin >> n2;
	trial_divisio_fac(n2);
	return 0;
}
#endif
#if 0
//��1��2��2��3��4��5���������֣�дһ��main��������ӡ�����в�ͬ�����У�

//�磺512234��412325�ȣ�Ҫ��"4"�����ڵ���λ��"3"��"5"����������

// str: �ַ���
// begin: �ַ�����һ���ַ�������
// end: �ַ������һ���ַ�������
// cnt: ͳ��ȫ���е���Ŀ������֮ǰ��ֵΪ0
#include "iostream"
#include "string"
#include "functional"
#include "numeric"
#include "algorithm"

using namespace std;
//����÷���ֵ��vector<string>���ս����ô�죿����
void string_full_permutation_containing_duplicate_char(char *str, int begin, int end, int &cnt)
{
	if (begin >= end)
	{
		if (strstr(str, "35") != NULL || strstr(str, "53") != NULL)
			return;
		std::cout << str << std::endl;
		++cnt;
		return;
	}
	if (begin > 2 && str[2] == '4')
		return;

	string_full_permutation_containing_duplicate_char(str, begin + 1, end, cnt);
	int i = begin + 1;
	while (i <= end)
	{
		if (str[begin] != str[i])
		{
			std::swap(str[begin], str[i]);
			string_full_permutation_containing_duplicate_char(str, begin + 1, end, cnt);
			std::swap(str[begin], str[i]);

			while (str[i] == str[i + 1])	//�������治��,��ʹ��ͬ����Ҳ������һ��
				++i;
		}
		++i;
	}
}

void string_full_permutation_containing_duplicate_char2(char *str, int begin, int end, int &cnt){
	//string str2 = str;
	//if (str[2] == '4' || str2.find_first_of("35") != string::npos)  {return;}  //����˼·
	if (begin >= end){
		if (strstr(str, "53") != nullptr || strstr(str, "35") != nullptr)
			return;
		++cnt;
		cout << "str== " << str << endl;
		return;
	}// 124 23526667
	if (begin > 2 && str[2] == '4')  //1..����ȡ����2������Ϊ=2ֻ�Ǵ���2�ţ�����2δ����4������Ҳ�͵���ȥ����4�ͺ��漸���Ľ�������
		return;
	//5...
	string_full_permutation_containing_duplicate_char2(str, begin + 1, end, cnt);
	for (int i = begin + 1; i <= end; ++i)  //2..������ȡ�� end������
	{
		if (str[i] != str[begin]){ //4..
			swap(str[i], str[begin]);
			string_full_permutation_containing_duplicate_char2(str, begin + 1, end, cnt);
			swap(str[i], str[begin]);
			//while (str[i] == str[i + 1])  //3..i+1������ࡣ������
			//	++i;
		}
			while (str[i] == str[i + 1])  //3..i+1������ࡣ������
				++i;
	}
}
int main(int argc, char **argv)
{
	char str[] = "142211";
	int len = strlen(str);
	int cnt = 0;
	string_full_permutation_containing_duplicate_char(str, 0, len - 1, cnt);
	cout << cnt << endl;
	cnt = 0;
	cout << ".............\n\n";

	//char str2[]{'1', '4', '3', '3','\0'};
	char str2[] = "142211";
	string_full_permutation_containing_duplicate_char2(str2, 0, len - 1, cnt);
	cout << endl << endl << cnt << endl;
}
#endif
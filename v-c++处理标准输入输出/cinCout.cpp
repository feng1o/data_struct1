#if 0
//http://note.youdao.com/share/?id=4d67ed2a111df899a752ebbc9eaeb02b&type=note
#include "iostream"
#include "iomanip"
#include "string"

using namespace std;
int main()
{

	int number;
	char ch;
	char a[200];
	string str1;
	cin >> str1;
	cout << str1;
	cout << "zbdde\0" << "skndg";
	cin >> ch;
	#if 01
cin >> a;
	cout << a << endl;
	cin  >> number >> ch; //����  123 23 3���ȡ123�� 2��
							//��ȡ����ʱ�����հ��ַ��������ո� tab���ͻس�����Ϊ��ֹ�ַ�
							//��������ȡ����ʱͨ���������еĿո� tab�����з��ȿհ��ַ���
	cout << '\0';  //����һ���ո��
	cout << setw(2) << number  << "  "<< setw(2) <<  ch << endl;
	//while (cin >> ch && ch != '\0')  //\0ʵ���ϲ��ᱻ���뵽����������ȥ�ģ������Զ��ӵģ�
	while (cin >> ch )
		cout << setw(2) << ch << endl;
	while (cin >> number)  //���� 123 23 3 ����123�� 23�� 3���ζ���
		cout << setw(2) << number << endl;
#endif
	string str;
	getline(cin, str);
	cout << str << endl;
	cout << str[2] << endl;
	return 0;
}


#endif
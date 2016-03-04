#if 0
#include "iostream"
#include "string"
using namespace std;

class permutaiton
{
public:
	permutaiton(char *chp = new char[]) :pchar(chp) { cout << "struct\n"; };
	permutaiton(const permutaiton & cpermu) :pchar(cpermu.pchar) { cout << ".....kaobei\n"; };
	~permutaiton(){  cout << "destruct\n"; };

	char* & operator()(int lhs,int rhs)
	{
		if (rhs == lhs)
		{
			std::cout << pchar << endl;
		}

		for (int i = lhs; i <= rhs;i++)
		{
			char temp = pchar[lhs];
			pchar[lhs] = pchar[i];
			pchar[i] = temp;
			operator()( lhs + 1, rhs);
			temp = pchar[lhs];
			pchar[lhs] = pchar[i];
			pchar[i] = temp;

		}
		return pchar;
	}
private:
	char *pchar;
};


void main()
{
	char *schar = "abc";
	permutaiton permu(schar);
	permutaiton *pe;
	permutaiton permu2(permu);
}
#endif

#if 01

#include <stdio.h>

void permutation(char s[], int b, int e)
{
	if ((0 <= b) && (b <= e))
	{
		if (b == e)
		{
			printf("%s\n", s);
		}
		else
		{
			int i = 0;

			for (i = b; i <= e; i++)
			{
				char c = s[b]; //一次把所有字符调到第一个位置，然后开始全排列后面的
				s[b] = s[i];
				s[i] = c;

				permutation(s, b + 1, e);

				c = s[b]; //交换回来，，，然后让他们继续
				s[b] = s[i];
				s[i] = c;
			}
		}
	}
}

int main()
{
	char s[] = "abc";

	permutation(s, 0, 3);

	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class Gauss
{
	static int idx;
	static int sum;
public:
	Gauss()
	{
		idx++;
		sum += idx;
	}
	void say(void)
	{
		cout << "Count = " << idx << ", Sum = " << sum << endl;
	}
};

int Gauss::idx = 0;
int Gauss::sum = 0;

int main(void)
{
	Gauss * p = new Gauss[10];
	p->say();
	delete[] p;
	return 0;
}
#endif
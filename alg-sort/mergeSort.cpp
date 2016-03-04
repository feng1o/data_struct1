
#include"iostream"

using std::cin;
using std::cout;
typedef int elementType;
class MergeSort
{
public:

	elementType* mergesort(elementType *A, int n){
		// write code here
		if (NULL == A || n < 2)
			return NULL;
		startDo(A, 0, n - 1);
		return A;
	}

	//  void startDo(int *a,int begin,int end);
	//  void sort(int *a,int begin ,int mid,int end);

	void startDo(int *a, int begin, int end)
	{
		int mid = (end + begin) / 2;
		if (begin == end)
			return;
		// if(0 != mid)

		startDo(a, begin, mid);
		startDo(a, mid + 1, end);

		sort(a, begin, mid, end); //这个放在strtDo的前后是不一样的！！递归的方式不一样！！！！！！
		//mid不可少！！！why
		//return;

	}
	void sort(int *a, int begin, int mid, int end) //排序后的插入，，要用new分配的原因
	{
		int *temp = new int[end - begin + 1];
		int l, r, k;
		l = begin;
		r = mid + 1;
		k = 0;
		while (l <= mid && r <= end)
		{
			if (a[l] <= a[r])
			{
				temp[k++] = a[l++];
			}
			if (a[l] > a[r])
			{
				//  r++;
				temp[k++] = a[r++];
			}
		}
		while (l <= mid)
			temp[k++] = a[l++];
		while (r <= end)
			temp[k++] = a[r++];
		for (int t = 0, m = begin; t < end - begin + 1; t++)
			a[m++] = temp[t];
		delete[] temp;

	}




	//elementType a[];
};

#if 0
int main()
{
	MergeSort xx;
	int a[] = { 1, 7, 3, 5 };
	int *p;
	p = xx.mergesort(a, 4);

	for (int i = 0; i < 4; i++)
	{
		cout << p[i] << std::endl;
	}
	return 0;

}
#endif
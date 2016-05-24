#include <iostream>
#include "vector"
using namespace std;
///
class Solution {
public:
	int InversePairs(vector<int> data) {
		int len = data.size();
		if (len <= 1)
			return 0;
		return partion(data, 0, len - 1);
	}
	int partion(vector<int> &data, int begin, int end){
		int mid = (end + begin) / 2;
		if (begin == end)
			return 0;
		int lnc = partion(data, begin, mid);
		int rnc = partion(data, mid + 1, end);

		vector<int> ivec(end - begin + 1, 0);
		int i = mid;
		int j = end;
		int index = end;
		int count = 0;
		while (i >= begin && j >= mid + 1){
			if (data[i] > data[j]){
				count += j - i;
				ivec[index--] = data[i--];
			}
			else{
				ivec[index--] = data[j--];
			}
		}
		for (; i >= begin; --i)
			ivec[index--] = data[i];
		for (; j >= mid + 1; --j)
			ivec[index--] = data[j];
		//data = ivec; //error
		for (int k = 0, m = begin; k <= end - begin; ++k)
			data[m++] = ivec[++index];
		return lnc + rnc + count;

	}
};

int main()
{
	vector<int> ivec{ 7, 5, 6, 4 };
	class Solution sol;
	cout << sol.InversePairs(ivec);
	return 0;
}
<<<<<<< Updated upstream
=======
//addd
>>>>>>> Stashed changes

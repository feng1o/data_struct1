#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int>::size_type len = input.size();

		if (len < k || k < 1) return ans;
		if (len == k) return input;
		partion(input, k, 0, len);
		return ans;

	}

	void partion(vector<int> input, int k, int begin, int end1){
		int key = input[end1 - 1];
		// int end = end1 - 1;
		if (begin < end1){
			while (1){
				while (begin < end1 && input[begin++] <= key);
				if (begin >= end1)
					break;
				while (end1 > 0 && input[--end1] > key);
				if (begin >= end1)
					break;
				swap(input[begin - 1], input[end1]);
			}
			swap(input[begin - 1], key);
		}
		if (begin == k);
		//  ans.insert(ans.begin(), input.begin(), input.begin()+k-1);
		ans.insert(ans.begin(), input.begin(), input.begin() + k - 1);
		if (begin < k)
			partion(input, k, begin - 1, end1);
		if (begin > k)
			partion(input, k, 0, begin);
	}
private:
	vector<int> ans;
};


int main()
{
	vector<int> input = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Solution sol;
	vector<int> ans = sol.GetLeastNumbers_Solution(input, 4);
	for (auto &it : ans)
		std::cout << it << endl;
	return 0;
}
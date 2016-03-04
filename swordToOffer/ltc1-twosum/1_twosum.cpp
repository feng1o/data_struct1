//vector<int> vans;
#include "iostream"
#include "string"
#include "iomanip"
#include "vector"


template<typename T>
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (i = 0; i < nums.size(); i++)
		{
			if (findNum(nums, i, 0, nums.size(), target))
				return vans;
		}
	}

	int findNum(vector<int> nums, int index, int begin, int end, int target)
	{
		int  n = (end + begin) / 2;
		if (nums[index] + nums[n] == target)
		{
			vans.push_back(index + 1);
			vans.push_back(n + 1);
			return true;
		}
		else if (nums[index] + nums[n] < target)
		{
			findNum(nums, index, n, end, target);
		}
		else if (nums[index] + nums[n] > target)
		{
			findNum(nums, index, begin, n, target);
		}
		return false;
	}


private:
	int i, j;
	vector<int> vans;
};
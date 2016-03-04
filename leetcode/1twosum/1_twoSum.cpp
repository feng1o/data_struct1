#if 01
/*
*仅仅适用于有序的，，无序的比较麻烦。。。。。。。。。。。。。。。。。。。。。。。
*对于一个有序数组，给一个值target，找看有么有两个和等target，
*https://leetcode.com/problems/two-sum/
*
*/
#include "iostream"
#include "string"
#include "iomanip"
#include "vector"

using namespace  std;
//template<typename T>
class Solution {
public:
	std::vector<int> twoSum(vector<int>& nums, int target) {
		for (i = 0; i < nums.size(); )
		{
			findNum(nums, i, 0, nums.size(), target);
			if (!vans.empty())
				return vans;
			else
				i++;
		}
		return vans;
	}
	void findNum(vector<int>& nums, int index, int begin, int end, int target)
	{
		if (begin == end - 1)
		{
			return ;
		}
		int  n = (end + begin) / 2;
		if (nums[index] + nums[n] == target)
		{
			//vans.insert(vans.begin(),n + 1);
			vans.push_back(index + 1);
			vans.push_back(n + 1);
			//vans.insert(vans.begin(), index + 1);
			return ;
		}
		else if (nums[index] + nums[n] < target)
		{
			findNum(nums, index, n, end, target);
		}
		else if (nums[index] + nums[n] > target)
		{
			findNum(nums, index, begin, n, target);
		}
		return ;
	}
	//int findNum(vector<int>& nums, int index, int begin, int end, int target)
	//{
	//	if (begin==end-1 )
	//	{
	//		return false;
	//	}
	//	int  n = (end + begin) / 2;
	//	if (nums[index] + nums[n] == target)
	//	{
	//		//vans.insert(vans.begin(),n + 1);
	//		vans.push_back(index + 1);
	//		vans.push_back(n + 1);
	//		//vans.insert(vans.begin(), index + 1);
	//		return true;
	//	}
	//	else if (nums[index] + nums[n] < target)
	//	{
	//		findNum(nums, index, n, end, target);
	//	}
	//	else if (nums[index] + nums[n] > target)
	//	{
	//		findNum(nums, index, begin, n, target);
	//	}
	//	return false;
	//}
	void getVectorValue()
	{
		if (vans.empty())
		{
			std::cout << "empty\n";
		}
		for (auto &it:vans)
		{
			std::cout << "vans value =" << it << std::endl;
		}
		//std::cout << "vans value1=" << this->vans[0] << "\nvans value2=" << vans.at(1) << std::endl;
	}
	Solution(){
		i = 0; j = 0;
	//	vans = { -1, -1 };
	}
private:
	int i, j;
	vector<int> vans ;
};

int main()
{
	vector<int> nums = { 2, 7,8,9 ,10,16,};
	int target = 19;
	Solution cS;
	cS.twoSum(nums, target);
	cS.getVectorValue();
}
#endif
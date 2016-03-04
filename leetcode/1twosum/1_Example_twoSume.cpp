#if 0
/*
*�˷�������������ģ���������������������������������������������������������������*******
*����һ���������飬��һ��ֵtarget���ҿ���ô�������͵�target��
*https://leetcode.com/problems/two-sum/
*/
#include "iostream"
#include "string"
#include "iomanip"
#include "vector"
#include "map"
#include "unordered_map"

using namespace  std;
//template<typename T>
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		//Key is the number and value is its index in the vector.
		unordered_map<int, int> hash;
		//vector<int> vans;
		for (int i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];

			//if numberToFind is found in map, return them
			if (hash.find(numberToFind) != hash.end()) {//MAP��find���û�У�������ȥ������
				//+1 because indices are NOT zero based
				vans.push_back(hash[numberToFind] + 1);
				vans.push_back(i + 1);
				printHash(hash);
				return vans;
			}
			//number was not found. Put it in the map.
			hash[numbers[i]] = i;
			printHash(hash);
		}
		return vans;
	}


	void getVectorValue()
	{
		if (vans.empty())
		{
			std::cout << "empty\n";
		}
		for (auto &it : vans)
		{
			std::cout << "vans value =" << it << std::endl;
		}
		//std::cout << "vans value1=" << this->vans[0] << "\nvans value2=" << vans.at(1) << std::endl;
	}
	void printHash(unordered_map<int,int> hash)
	{
		for (auto &hit : hash)
		{
			std::cout << "vector�����ֵ" << hit.first << " ���ִ��� " << hit.second << std::endl;

		}std::cout << "\n\n";
	}
private:
	int i, j;
	vector<int> vans;
};

int main()
{
	vector<int> nums = { 2, 7, 8, 9, 10, 16, 0,23,5,2,6,0 };
	int target = 0;
	Solution cS;
	cS.twoSum(nums, target);
	cS.getVectorValue();
}
#endif
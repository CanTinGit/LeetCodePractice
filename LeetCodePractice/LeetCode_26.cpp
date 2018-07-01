/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	//Slow - my version
	//int removeDuplicates(vector<int>& nums)
	//{
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		for (int j = i+1; j < nums.size(); j++)
	//		{
	//			if (nums[j] == nums[i])
	//			{
	//				std::vector<int>::iterator it = nums.begin() + j;
	//				nums.erase(it);
	//				nums.shrink_to_fit();
	//				j--;
	//			}
	//			else if (nums[j] > nums[i])
	//			{
	//				break;
	//			}
	//		}
	//	}
	//	return nums.size();
	//}
	//// So quick version
	//int removeDuplicates(vector<int>& nums) {
	//	auto sz = nums.size();

	//	if (sz <= 1) {
	//		return sz;
	//	}
	//	auto cur = 1;

	//	for (auto i = 1; i<sz; i++) {
	//		if (nums[i - 1] != nums[i]) {
	//			nums[cur] = nums[i];
	//			cur++;
	//		}
	//	}

	int removeDuplicates(vector<int>& nums) 
	{
		if (nums.size() <= 1) return nums.size();
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				nums[j++] = nums[i];
			}
			else {
				if (nums[i] != nums[j - 1]) {
					nums[j++] = nums[i];
				}
			}
		}
		return j;
	}

	//	return cur;
	//}

};

//int main() {
//	vector<int> nums;
//	nums.push_back(0);
//	nums.push_back(0);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(3);
//	nums.push_back(4);
//
//	//std::vector<int>::iterator it = nums.begin()+1;
//	//nums.erase(it);
//
//	int ret = Solution().removeDuplicates(nums);
//	nums.resize(ret);
//
//	for (auto i = nums.begin(); i != nums.end(); i++) 
//	{
//		cout << *i << " ";
//	}
//	int j;
//	cin >> j;
//	return 0;
//}

//Result: Pass
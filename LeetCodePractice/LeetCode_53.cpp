/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example :
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
#include<vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int i, j;
		int sum = 0;
		for (i = 0; i<nums.size(); i++) {
			sum += nums[i];
			ans = Max(sum, ans);
			sum = Max(sum, 0);
		}
		return ans;
	}
	int Max(int num1, int num2)
	{
		if (num1 > num2) return num1;
		else return num2;
	}
};
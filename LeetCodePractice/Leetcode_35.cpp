/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example
Input: [1,3,5,6], 5
Output: 2

Input: [1,3,5,6], 7
Output: 1
min max j 
0    3  1
1    3  2
2    3  3

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int min, max;
		min = 0;
		max = nums.size() - 1;
		while (!(max < min))
		{
			int mid = (min + max) / 2;
			if (target < nums[mid])
			{
				max = mid - 1;
				if (max<min) return min;
			}
			else if (target > nums[mid])
			{
				min = mid + 1;
				if (max<min) return min;
			}
			else return mid;
		}

	}
};

//Result: Pass
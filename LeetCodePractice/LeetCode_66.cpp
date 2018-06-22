/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size()-1; i >= 0; i--)
		{
			if (i == digits.size() - 1)
			{
				digits[i] += 1;
			}
			if (i == 0)
			{
				if (digits[i] >= 10)
				{
					digits[1] = 1;
					digits.push_back(0);
					return digits;
				}
			}
			if (digits[i] >= 10)
			{
				digits[i + 1] += 1;
				digits[i] = 0;
			}
			else
			{
				return digits;
			}
		}
		
	}
};

//Result: Pass
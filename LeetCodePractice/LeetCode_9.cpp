/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/
#include <iostream>
#include <vector>
class Solution {
public:
	//My solution - right but too slow
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		std::vector<int> nums;
		int division = 10;
		while(x > 0)
		{
			int y = x % division;
			nums.push_back(y);
			x = x / division;
		}
		auto rbegin = nums.rbegin();
		auto lbegin = nums.begin();
		for (int i = 0; i < nums.size()/2; i++)
		{
			if (*lbegin == *rbegin)
			{
				lbegin++;
				rbegin++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	//only reversing till half and then compare
	//bool isPalindrome(int x) {
	//	if (x<0 || (x != 0 && x % 10 == 0)) return false;
	//	int sum = 0;
	//	while (x>sum)
	//	{
	//		sum = sum * 10 + x % 10;
	//		x = x / 10;
	//	}
	//	return (x == sum) || (x == sum / 10);
	//}
};
int main()
{
	bool result = Solution().isPalindrome(10);
	std::cout << result << std::endl;
}
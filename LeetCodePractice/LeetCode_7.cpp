/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321
*/
#include <iostream>
#include<vector>
#include <cmath>
#include <cstdlib>
class Solution {
public:
	/*
	 int reverse(int x) {
		if (x > 0x7FFFFFFF && x < LONG_MIN)
		{
			return 0;
		}
		else
		{
			int y, count;
			unsigned long result;
			bool isNegative;
			isNegative = false;
			y = 10;
			count = 0;
			result = 0;
			if (x < 0)
			{
				x = x * -1;
				isNegative = true;
			}
			while (x>=y && count<8)
			{
				y = y * 10;
				count++;
			}

			if (count == 8)
			{
				count++;
			}
			else y = y / 10;
			int i = 0;
			while(x>0)
			{
				int figure;
				if (x<10)
				{
					figure = x;
				}
				else { figure = x / y; }
				result = result + figure * giveten(i);
				x = x - figure * y;
				y = y / 10;
				i++;
			}
			if (result > LONG_MAX)
			{
				return 0;
			}
			if (isNegative)
			{
				result = result * -1;
				return result;
			}
			else
				return result;
		}

	}

	int giveten(int n)
	{
		int result = 1;
		for (int i = 0; i<n; i++) {
			result = result * 10;
		}
		return result;
	}
	*/
	bool is_range_int(long long x)
	{
		return std::numeric_limits<int>::min() <= x &&
			x <= std::numeric_limits<int>::max();
	}

	int reverse(int x)
	{
		if (x == 0) return 0;
		const bool neg = x < 0 ? true : false;
		long long result = 0;
		x = std::fabs(x);
		while (x != 0) {
			//use %10 but not /10
			result = result * 10 + x % 10;
			x /= 10;
		}
		//check the range and if it is negative to decide the return value
		return !is_range_int(result) ? 0
			: neg ? -result : result;
	}
};

int main ()
{
	Solution().reverse(10);
}
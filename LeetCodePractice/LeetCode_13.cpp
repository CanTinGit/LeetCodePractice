/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <iostream>
#include <map>
#include <string>
class Solution {
public:
	int romanToInt(std::string s) {
		if (s.empty())
		{
			return 0;
		}
		std::map<char, int> t = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000 } };
		int result = 0;
		for (int i = 0; i <s.length()-1; i++)
		{
			if (t[s[i]]<t[s[i+1]])
			{
				result -= t[s[i]];
			}
			else
			{
				result += t[s[i]];
			}
		}
		// if we change i < s.length(), i+1 will beyond the range when i = s.length()-1
		result += t[s.back()];
	}

	// using function to translate char to int will increase the speed, maybe it's because use key to find result in map take more time
	//int chartoInt(char r) {
	//	if (r == 'I')
	//		return 1;
	//	if (r == 'V')
	//		return 5;
	//	if (r == 'X')
	//		return 10;
	//	if (r == 'L')
	//		return 50;
	//	if (r == 'C')
	//		return 100;
	//	if (r == 'D')
	//		return 500;
	//	if (r == 'M')
	//		return 1000;
	//	else
	//		return -1;
	//}
	//int romanToInt(string s) {
	//	int res = 0;
	//	for (int i = 0; i<s.length(); i++)
	//	{
	//		int s1 = chartoInt(s[i]);
	//		if (i + 1 < s.length())
	//		{
	//			int s2 = chartoInt(s[i + 1]);
	//			if (s1 >= s2)
	//				res = s1 + res;
	//			else
	//			{
	//				res = res + s2 - s1;
	//				i++;
	//			}
	//		}
	//		else
	//		{
	//			res = res + s1;
	//			i++;
	//		}
	//	}
	//	return res;
	//}
};
//int main()
//{
//	bool result = Solution().romanToInt("LVI");
//	std::cout << result << std::endl;
//}
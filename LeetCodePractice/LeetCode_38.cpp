/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string s = "1";
		for (int i = 1; i<n; ++i) {
			string ns = "";
			int start = 0;
			while (start<s.size()) {
				char c = s[start];
				int end = start + 1;
				while (end<s.size() && s[end] == c) end++;
				int len = end - start;
				ns = ns + char(len + '0') + c;
				start = end;
			}
			s = ns;
		}
		return s;
	}

	//µÝ¹é·¨£º
	//string countAndSay(int n) {
	//	if (n <= 1)
	//		return "1";
	//	return generate(countAndSay(n - 1));
	//}

	//string generate(string s)
	//{
	//	string result = "";
	//	int n = s.size(), i, cnt = 1;
	//	for (i = 0; i<n - 1; i++)
	//	{
	//		if (s[i] == s[i + 1]) cnt++;
	//		else {
	//			result += to_string(cnt) + s[i];
	//			cnt = 1;
	//		}
	//	}
	//	result += to_string(cnt) + s[i];
	//	return result;
	//}
};
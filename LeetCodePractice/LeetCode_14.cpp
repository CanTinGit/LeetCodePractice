/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int cur = -1;
		bool cycle = true;
		if (strs.size() <= 0)
		{
			return "";
		}
		while(cycle)
		{
			cur++;
			if (cur >= strs[0].length())
			{
				cycle = false;
				break;
			}
			char s = strs[0][cur];
			for (auto i = 0; i < strs.size(); i++)
			{
				if (cur < strs[i].length())
				{
					if (strs[i][cur] != s)
					{
						cycle = false;
						break;
					}
				}
				else
				{
					cycle = false;
					break;
				}
			}
		}
		if (cur<=0)
		{
			return "";
		}
		string s = strs[0].substr(0, cur);
		return s;
	}
};

//void main()
//{
//	vector<string> s;
//	s.push_back("aa");
//	s.push_back("a");
//	s.push_back("flight");
//
//	Solution().longestCommonPrefix(s);
//
//}

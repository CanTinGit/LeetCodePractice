/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	bool isValid(string s) 
	{
		vector<char> stack;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			{
				stack.push_back(s[i]);
			}
			else
			{
				if (stack.size()>0)
				{
					if (s[i] == '}')
					{
						if (stack.back() == '{')
						{
							stack.pop_back();
						}
						else
						{
							return false;
						}
					}
					else if (s[i] == ')')
					{
						if (stack.back() == '(')
						{
							stack.pop_back();
						}
						else
						{
							return false;
						}
					}
					else
					{
						if (stack.back() == '[')
						{
							stack.pop_back();
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
		if (stack.size() == 0)
		{
			return true;
		}
	}

	//Use map to set matching rule and use stack to match string is better

	//bool isValid(string s) {

	//	if (s.length()<1)
	//		return true;

	//	map<char, char> match;
	//	match[')'] = '(';
	//	match['}'] = '{';
	//	match[']'] = '[';

	//	vector<char> brackets;

	//	for (int i = 0; i<s.length(); ++i)
	//	{
	//		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
	//			brackets.push_back(s[i]);
	//		else
	//		{
	//			if (brackets.size()<1 || (match[s[i]] != brackets[brackets.size() - 1]))
	//				return false;
	//			else
	//				brackets.pop_back();
	//		}
	//	}

	//	if (!brackets.empty())
	//		return false;

	//	return true;
	//}
};

void main()
{
	Solution().isValid("()");
}


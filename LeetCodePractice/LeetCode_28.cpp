/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle)
	{
		if (needle.size() == 0)
		{
			return 0;
		}
		int curOfNeedle = 0;
		int index;
		bool isComparing = false;
		for (int i = 0; i < haystack.size(); i++)
		{
			if (needle[0] == haystack[i])
			{
				if (needle.size() == 1)
				{
					return 0;
				}
				for (int j = 1; j < needle.size(); j++)
				{
					if (haystack[i+j] != needle[j])
					{
						break;
					}
					if (j == needle.size()-1 && haystack[i + j] == needle[j])
					{
						return i;
					}
				}
			}
		}
		return -1;
	}

	//KMP表匹配法明显更好
	/*vector<int> kmp_table(const string & W) {
		int l = W.length();
		vector<int> T(l);
		int pos = 1;
		int cnd = 0;
		T[0] = -1;
		while (pos < l) {
			if (W[pos] == W[cnd]) {
				T[pos] = T[cnd];
			}
			else {
				T[pos] = cnd;
				cnd = T[cnd];
				while (cnd >= 0 && W[pos] != W[cnd])
					cnd = T[cnd];
			}
			pos++; cnd++;
		}
		return T;
	}
	int strStr(string haystack, string needle) {
		if (needle == "") return 0;
		int np = 0;
		int j = 0; int k = 0;
		vector<int> T = kmp_table(needle);
		int sl = haystack.length();
		int wl = needle.length();
		while (j < sl) {
			if (needle[k] == haystack[j]) {
				j++; k++;
				if (k == wl)
					return j - k;
			}
			else {
				k = T[k];
				if (k < 0) {
					j++; k++;
				}
			}
		}
		return -1;
	}*/
};
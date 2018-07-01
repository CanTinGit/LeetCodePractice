/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example :
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
#include <iostream>
#include<sstream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int cur = 0;
		for (int i = 0; i<n; i++)
		{
			if (cur > m && cur < m + n)
			{
				nums1[cur] = nums2[i];
				cur++;
				continue;
			}
			int result = BinarySearch(nums1, cur, m, nums2[i]);
			cur = result;
			if (cur >= m)
			{
				nums1[cur] = nums2[i];
				cur++;
			}
			else
			{
				nums1.insert(nums1.begin() + cur, nums2[i]);
			}
		}
		nums1.resize(m + n);
	}

	int BinarySearch(vector<int>& nums, int mn, int m, int target)
	{
		int min = mn;
		int max = m;
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

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		int m = stringToInteger(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);
		getline(cin, line);
		int n = stringToInteger(line);

		Solution().merge(nums1, m, nums2, n);

		string out = integerVectorToString(nums1);
		cout << out << endl;
	}
	return 0;
}
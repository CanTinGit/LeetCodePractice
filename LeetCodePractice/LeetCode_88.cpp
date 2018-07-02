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
#include <vector>
#include <algorithm>
using namespace std;
// My solution - take too much time - O(n^2)
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int cur = 0;
		int max = m;
		for (int i = 0; i<n; i++)
		{
			if (cur > m - 1 && cur < m + n)
			{
				nums1[cur] = nums2[i];
				cur++;
				continue;
			}
			int result = BinarySearch(nums1, cur, m, nums2[i]);
			cur = result;
			if (cur > m - 1)
			{
				nums1[cur] = nums2[i];
				cur++;
			}
			else
			{
				nums1.insert(nums1.begin() + cur, nums2[i]);
				m++;
			}
		}
		nums1.resize(max + n);
	}

	int BinarySearch(vector<int>& nums, int mn, int m, int target)
	{
		int min = mn;
		int max = m - 1;
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
/*
// least time solution
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m + n - 1;
		--m; --n;
		while (m >= 0 && n >= 0) {
			if (nums1[m] > nums2[n]) {
				nums1[pos--] = nums1[m--];
			}
			else nums1[pos--] = nums2[n--];
		}
		while (n >= 0) {
			nums1[pos--] = nums2[n--];
		}
	}
	// easier to understand
	//	it's checking (i>=0) and (nums1[i] > nums2[j] ), if both true, nums1[tar] = nums1[i], if not , nums1[tar] = nums2[j];
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, tar = m + n - 1;
		while (j >= 0) {
			if (i >= 0) {
				nums1[tar--] = nums2[j] > nums1[i] ? nums2[j--] : nums1[i--];
			}
			else {
				nums1[tar--] = nums2[j--];
			}
		}
	}


};	*/


//
//int main() {
//	vector<int> nums1;
//	vector<int> nums2;
//	nums1.push_back(1);
//	nums1.push_back(2);
//	nums1.push_back(3);
//	nums1.push_back(0);
//	nums1.push_back(0);
//	nums1.push_back(0);
//	nums2.push_back(2);
//	nums2.push_back(5);
//	nums2.push_back(6);
//
//	//std::vector<int>::iterator it = nums.begin()+1;
//	//nums.erase(it);
//
//	Solution().merge(nums1,3,nums2,3);
//
//	for (auto i = nums1.begin(); i != nums1.end(); i++) 
//	{
//		cout << *i << " ";
//	}
//	int j;
//	cin >> j;
//	return 0;
//}

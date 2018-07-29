/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		bool needSetZero = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
			{
				if (needSetZero)
				{
					length = 0;
					needSetZero = false;
				}
				length++;
			}
			else
			{
				needSetZero = true;
			}
		}
		return length;
	}

	//�ٶȸ��췽����Ŀǰ��δ���Ϊʲô��ʱ�临�Ӷ����Ե�һЩ�������ڴ˷���
	//int lengthOfLastWord(string s) {
	//	string str = s;
	//	int size = str.length();
	//	if (size == 0)
	//		return 0;
	//	int ch = 0;
	//	for (int j = 0; j<size; j++) {
	//		if (str[j] == ' ')
	//			ch++;
	//	}
	//	if (ch == size)
	//		return 0;
	//	int i = size - 1, count = 0;
	//	while (str[i] == ' ')
	//		i--;
	//	while (str[i] != ' ' && str[i] != '\0') {
	//		count++;
	//		i--;
	//	}
	//	return count;
	//}
};

void main()
{
	string k = "";
	int a = k.size();
	cout << a;
	cin >> a;
}

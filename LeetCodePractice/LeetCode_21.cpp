/*
Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output : 1->1->2->3->4->4
*/

#include <iostream>
#include <vector>
#include <string>


 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* head = l1;
		if (l1 == NULL || (l1 != NULL && l2 != NULL && l1->val > l2->val)) {
			head = l2;
		}

		ListNode* pre = NULL;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				ListNode* tmpNode = l1->next;
				l1->next = l2;
				if (pre != NULL) {
					pre->next = l1;
				}
				pre = l1;
				l1 = tmpNode;
			}
			else {
				pre = l2;
				l2 = l2->next;
			}
		}

		if (l1 != NULL && pre != NULL) {
			pre->next = l1;
		}

		return head;
	
	}
};

void main()
{
	
}
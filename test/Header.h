
#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	Solution() {}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *l = head;
		int carry = 0;
		while (l1 != NULL || l2!= NULL) {
			int x = (l1 != NULL) ? l1->val : 0;
			int y = (l2 != NULL) ? l2->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			l->next = new ListNode(sum % 10);
			l = l->next;
			if (l1 != NULL) l1 = l1->next;
			if (l2 != NULL) l2 = l2->next;
		}
		if (carry == 1) {
			ListNode *lastNode = new ListNode(1);
			l->next = lastNode;
		}

		return head;
	}
};

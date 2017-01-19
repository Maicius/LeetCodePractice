
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
		ListNode *l = new ListNode(1);
		ListNode *head;
		int carry;
		l->val = l1->val + l2->val;
		if (l->val >= 10) {
			head = l;
			head->val = head->val - 10;
			carry = 1;
		}
		else {
			head = l;
			carry = 0;
		}
		if (l2->next == NULL && l1->next !=NULL) {
			l1 = l1->next;
			l->next = l1;
			if (carry == 1) {
				l->next->val += carry;
				if (l->next->val >= 10) {
					l->next->val = l->next->val - 10;
					l = l->next;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
		}
		if (l2->next != NULL && l1->next == NULL) {
			l2 = l2->next;
			l->next = l2;
			if (carry == 1) {
				l->next->val += carry;
				if (l->next->val >= 10) {
					l->next->val = l->next->val - 10;
					l = l->next;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
		}
		else {
			while (l1->next != NULL && l2->next != NULL) {
				l1 = l1->next;
				l2 = l2->next;
				ListNode *Node = new ListNode(0);
				l->next = Node;
				l = l->next;
				l->val = l1->val + l2->val;
				l->val += carry;
				if (l->val >= 10) {
					l->val = l->val - 10;
					carry = 1;
				}
				else {
					carry = 0;
				}

			}
		}
		if (carry == 1) {
			ListNode *lastNode= new ListNode(1);
			l->next = lastNode;
		}
		if (l1->next == NULL && l2->next != NULL) {
			l->next = l2;
		}
		else if (l1->next != NULL && l2->next == NULL)
			l->next = l1;

		return head;
	}
};

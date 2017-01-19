#include<stdio.h>
#include<iostream>
#include"Header.h"
int main() {
	Solution *solution = new Solution();
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(9);
	ListNode *l3 = new ListNode(9);
	//ListNode *l4 = new ListNode(5);
	//ListNode *l5 = new ListNode(6);
	//ListNode *l6 = new ListNode(4);
	l2->next= l3;

	solution->addTwoNumbers(l1, l2);

	
}
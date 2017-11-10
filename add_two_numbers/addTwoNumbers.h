#pragma once
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* l = new ListNode(0);
		ListNode *ll = l;
		while (l1 || l2)
		{
			int sum = 0;
			ListNode *temp = new ListNode(0);
			if (l1 && l2)
				sum = l1->val + l2->val + carry;
			else if (!l1)
				sum = l2->val + carry;
			else
				sum = l1->val + carry;
			if (carry)
				carry = 0;
			temp->val = sum % 10;
			ll->next = temp;
			ll = temp;
			if (sum >= 10)
				carry = 1;
			if (l1&&l2) {
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (!l1)
				l2 = l2->next;
			else
				l1 = l1->next;
		}
		if (carry) {
			ListNode *temp = new ListNode(0);
			temp->val = 1;
			ll->next = temp;
		}
		return l->next;
	}
};
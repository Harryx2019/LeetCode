#pragma once
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int s, d = 0;
		ListNode* ans = new ListNode(0);
		ListNode* p = ans;
		while (l1 != NULL && l2 != NULL) {
			s = l1->val + l2->val + d;
			d = s / 10;
			p->val = s % 10;
			p->next = new ListNode(d);
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			s = l1->val + d;
			d = s / 10;
			p->val = s % 10;
			p->next = new ListNode(0);
			p = p->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			s = l2->val + d;
			d = s / 10;
			p->val = s % 10;
			p->next = new ListNode(0);
			p = p->next;
			l2 = l2->next;
		}
		if (d != 0) {
			p->val = d;
			return ans;
		}
		ListNode* q = ans;
		p = ans->next;
		while (p->next != NULL) {
			q = p;
			p = p->next;
		}
		q->next = NULL;
		return ans;
	}
};
void solution2();
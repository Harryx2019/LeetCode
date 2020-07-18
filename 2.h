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
		ListNode* q = ans;
		while (l1 != NULL || l2 != NULL) {
			s = d;
			if (l1 != NULL) {
				s += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				s += l2->val;
				l2 = l2->next;
			}
			d = s / 10;
			p->val = s % 10;
			p->next = new ListNode(0);
			q = p;
			p = p->next;
		}
		if (d != 0) {
			p->val = d;
			return ans;
		}
		q->next = NULL;
		return ans;
	}
};
void solution2();
#include <iostream>
#include "109.h"
using namespace std;

void solution109() {
	ListNode* head = new ListNode();
	ListNode* p = head;
	ListNode* pre = nullptr;
	int num;
	while(1) {
		cin >> num;
		if (num == -1) {
			pre->next = nullptr;
			break;
		}
		p->val = num;
		p->next = new ListNode();
		pre = p;
		p = p->next;
	}
	Solution109 s;
	s.sortedListToBST(head);
}
#include <iostream>
#include "2.h"
using namespace std;

void solution2() {
	ListNode* l1 = new ListNode(0);
	ListNode* l2 = new ListNode(0);
	//输入链表l1
	ListNode* p = l1;
	do {
		cin >> p->val;
		p->next = new ListNode(0);
		p = p->next;
	} while (cin.get() != '\n');
	ListNode* q = l1;
	p = l1->next;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	//输入链表l2
	p = l2;
	do {
		cin >> p->val;
		p->next = new ListNode(0);
		p = p->next;
	} while (cin.get() != '\n');
	q = l2;
	p = l2->next;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;

	Solution2 s;
	p = s.addTwoNumbers(l1, l2);
	cout << p->val;
	p = p->next;
	while (p != NULL) {
		cout << "->" << p->val;
		p = p->next;
	}
}
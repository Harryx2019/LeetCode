#include "100.h"
#include <queue>
#include <iostream>

void solution100() {
	queue<TreeNode*> q;
	cout << "������1���ڵ㣺";
	int num;
	cin >> num;
	TreeNode* root1 = new TreeNode(num);
	q.push(root1);
	while (!q.empty()) {
		TreeNode* p = q.front();
		q.pop();
		cout << "����ڵ�" << p->val << "����ڵ㣺";
		cin >> num;
		if (num == -1) {
			p->left = nullptr;
		}
		else {
			TreeNode* node = new TreeNode(num);
			p->left = node;
			q.push(node);
		}

		cout << "����ڵ�" << p->val << "���ҽڵ㣺";
		cin >> num;
		if (num == -1) {
			p->right = nullptr;
		}
		else {
			TreeNode* node = new TreeNode(num);
			p->right = node;
			q.push(node);
		}
	}

	cout << "������2���ڵ㣺";
	cin >> num;
	TreeNode* root2 = new TreeNode(num);
	q.push(root2);
	while (!q.empty()) {
		TreeNode* p = q.front();
		q.pop();
		cout << "����ڵ�" << p->val << "����ڵ㣺";
		cin >> num;
		if (num == -1) {
			p->left = nullptr;
		}
		else {
			TreeNode* node = new TreeNode(num);
			p->left = node;
			q.push(node);
		}

		cout << "����ڵ�" << p->val << "���ҽڵ㣺";
		cin >> num;
		if (num == -1) {
			p->right = nullptr;
		}
		else {
			TreeNode* node = new TreeNode(num);
			p->right = node;
			q.push(node);
		}
	}

	Solution100 s;
	cout << s.isSameTree(root1, root2);
}
#include "337.h"
#include <iostream>
#include <queue>
void solution337() {
	queue<TreeNode*> q;
	cout << "输入根节点：";
	int num;
	cin >> num;
	TreeNode* root = new TreeNode(num);
	q.push(root);
	while (!q.empty()) {
		TreeNode* p = q.front();
		q.pop();
		cout << "输入节点" << p->val << "的左节点：";
		cin >> num;
		if (num == -1) {
			p->left = nullptr;
		}
		else {
			TreeNode* node = new TreeNode(num);
			p->left = node;
			q.push(node);
		}

		cout << "输入节点" << p->val << "的右节点：";
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
	Solution337 s;
	cout << s.rob(root);
}
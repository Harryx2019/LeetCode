#include <iostream>
#include <queue>
#include "95.h"
using namespace std;
void solution95() {
	int n;
	cin >> n;
	vector<TreeNode*> allTrees;
	Solution95 s;
	allTrees=s.generateTrees(n);
	queue<TreeNode*> tree;
	TreeNode* node;
	for (auto& Node : allTrees) {
		tree.push(Node);
		while (!tree.empty()) {
			node = tree.front();
			if (node == nullptr) {
				cout << "null" << " ";
				tree.pop();
			}
			else {
				cout << node->val << " ";
				tree.pop();
				if (node->left == nullptr && node->right == nullptr) {
					continue;
				}
				tree.push(node->left);
				if (node->right != nullptr) {
					tree.push(node->right);
				}
			}
		}
		cout << endl;
	}
}
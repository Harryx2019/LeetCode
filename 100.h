#pragma once
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution100 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}
		if ((p == nullptr && q != nullptr) || (q == nullptr && p != nullptr)) {
			return false;
		}
		if (p->val != q->val) {
			return false;
		}
		TreeNode* root1 = p;
		TreeNode* root2 = q;
		stack<TreeNode*> stack1;
		stack<TreeNode*> stack2;

		while ((root1 != nullptr || !stack1.empty()) && (root2 != nullptr || !stack2.empty())) {
			if ((root1 == nullptr && root2 != nullptr) || (root2 == nullptr && root1 != nullptr)) {
				return false;
			}
			if (root1 == nullptr && root2 == nullptr) {
				root1 = stack1.top()->right;
				stack1.pop();

				root2 = stack2.top()->right;
				stack2.pop();
			}
			else {
				if (root1->val != root2->val) {
					return false;
				}
				else {
					stack1.push(root1);
					root1 = root1->left;

					stack2.push(root2);
					root2 = root2->left;
				}
			}
		}
		if (root1 == nullptr && stack1.empty() && root2 == nullptr && stack2.empty()) {
			return true;
		}
		return false;
	}
};

void solution100();
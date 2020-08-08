#pragma once
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution337 {
public:
	int rob(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		unordered_map<TreeNode*, int> f, g;
		stack<TreeNode*> stack;
		TreeNode* p = root;
		TreeNode* pcur = nullptr;
		while (!stack.empty() || p != nullptr) {
			if (p != nullptr) {
				stack.push(p);
				p = p->left;
			}
			else {
				p = stack.top();
				if (p->right && p->right != pcur) {
					p = p->right;
					stack.push(p);
					p = p->left;
				}
				else {
					stack.pop();
					f[p] = p->val + g[p->left] + g[p->right];
					g[p] = max(f[p->left], g[p->left]) + max(f[p->right], g[p->right]);
					pcur = p;
					p = nullptr;
				}
			}
		}
		return max(f[root], g[root]);
	}
};
void solution337();
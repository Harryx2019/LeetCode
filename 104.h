#pragma once
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int length = 0;
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty()) {
			int sz = Q.size();
			while (sz > 0) {
				TreeNode* p = Q.front();
				Q.pop();
				if (p->left) {
					Q.push(p->left);
				}
				if (p->right) {
					Q.push(p->right);
				}
				sz--;
			}
			length++;
		}
		return length;

		/*int length = 0;
		TreeNode* p = root;
		stack<TreeNode*> s;
		while (p != NULL) {
			if (p->left != NULL || p->right != NULL) {
				s.push(p);
				length = max(length, (int)s.size());
				p = p->left != NULL ? p->left : p->right;
				continue;
			}
			length = max(length, (int)s.size() + 1);
			while (!s.empty()) {
				if (s.top()->right != NULL && s.top()->right != p) {
					p = s.top()->right;
					break;
				}
				p = s.top();
				s.pop();
			}
		}
		return length;*/
	}
};

void solution104();
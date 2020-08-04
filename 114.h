#pragma once
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution114 {
public:
	void flatten(TreeNode* root) {
		// 方法一： 栈和链表相结合进行前序遍历
		vector<TreeNode*> v;
		stack<TreeNode*> stk;
		TreeNode* p = root;
		while (!stk.empty() || p != nullptr) {
			while (p != nullptr) {
				v.push_back(p);
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			p = p->right;
		}
		for (int i = 1; i < v.size(); i++) {
			TreeNode* prev = v[i - 1], * cur = v[i];
			prev->left = nullptr;
			prev->right = cur;
		}
		// 方法二：利用栈进行原地展开
		/*if (root == nullptr) {
			return;
		}
		stack<TreeNode*> stk;
		stk.push(root);
		TreeNode* prev = nullptr;
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			if (prev != nullptr) {
				prev->left = nullptr;
				prev->right = cur;
			}
			TreeNode* right = cur->right;
			if (right != nullptr) {
				stk.push(right);
			}
			TreeNode* left = cur->left;
			if (left != nullptr) {
				stk.push(left);
			}
			prev = cur;
		}*/
		// 方法三：寻找前驱节点
		/*TreeNode* curr = root;
		while (curr != nullptr) {
			if (curr->left != nullptr) {
				TreeNode* next = curr->left;
				TreeNode* prev = next;
				while (prev->right != nullptr) {
					prev = prev->right;
				}
				prev->right = curr->right;
				curr->right = next;
				curr->left = nullptr;
			}
			curr = curr->right;
		}*/
	}
};

void solution114();
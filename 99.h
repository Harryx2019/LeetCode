#pragma once
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution99 {
public:
	void inorder(TreeNode* root, vector<int>& order) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left, order);
		order.push_back(root->val);
		inorder(root->right, order);
	}
	void findTwoSwapped(vector<int> order, int& x, int& y) {
		x = -1;
		y = -1;
		int n = order.size();
		for (int i = 0; i < n - 1; i++) {
			if (order[i + 1] < order[i]) {
				y = order[i + 1];
				if (x == -1) {
					x = order[i];
				}
				else {
					return;
				}
			}
		}
	}
	void recover(TreeNode* root, int count, int x, int y) {
		if (root == nullptr) {
			return;
		}
		if (root->val == x || root->val == y) {
			root->val = root->val == x ? y : x;
			if (--count == 0) {
				return;
			}
		}
		recover(root->left, count, x, y);
		recover(root->right, count, x, y);
	}
	void recoverTree(TreeNode* root) {
		//方法1：递归中序遍历（数组存储）
		/*vector<int> order;
		inorder(root, order);
		int x, y;
		findTwoSwapped(order, x, y);
		recover(root, 2, x, y);*/

		// 方法2 ：循环中序遍历（栈存储）
		/*stack<TreeNode*> stack;
		TreeNode* x = nullptr;
		TreeNode* y = nullptr;
		TreeNode* prev = nullptr;
		while (!stack.empty() || root != nullptr) {
			while (root != nullptr) {
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			if (prev != nullptr && root->val < prev->val) {
				y = root;
				if (x == nullptr) {
					x = prev;
				}
				else {
					break;
				}
			}
			prev = root;
			root = root->right;
		}
		swap(x->val, y->val);*/

		// 方法3： Morris遍历（无存储）
		TreeNode* x = nullptr;
		TreeNode* y = nullptr;
		TreeNode* predecessor = nullptr;
		TreeNode* prev = nullptr;
		while (root != nullptr) {
			if (root->left != nullptr) {
				predecessor = root->left;
				while (predecessor != nullptr && predecessor != root) {
					predecessor = predecessor->right;
				}
				if (predecessor == nullptr) {
					predecessor = root;
					root = root->left;
				}
				else {
					if (prev != nullptr && root->val < prev->val) {
						y = root;
						if (x == nullptr) {
							x = prev;
						}
					}
					prev = root;

					predecessor->right = nullptr;
					root = root->right;
				}
			}
			else {
				if (prev != nullptr && root->val < prev->val) {
					y = root;
					if (x == nullptr) {
						x = prev;
					}
				}
				prev = root;
				root = root->right;
			}
		}
		swap(x->val, y->val);
	}
};
void solution99();
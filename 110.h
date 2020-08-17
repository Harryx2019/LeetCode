#pragma once
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution110 {
public:
	int lengthOfBitree(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return 1 + max(lengthOfBitree(root->left), lengthOfBitree(root->right));
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		int leftLength = lengthOfBitree(root->left);
		int rightLength = lengthOfBitree(root->right);
		if (abs(leftLength - rightLength) < 2) {
			if (isBalanced(root->left) && isBalanced(root->right)) {
				return true;
			}
		}
		return false;
	}
};

void solution110();
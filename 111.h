#pragma once
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution111 {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr) {
			return 1;
		}
		int leftLength = INT_MAX;
		if (root->left != nullptr) {
			leftLength = minDepth(root->left);
		}

		int rightLength = INT_MAX;
		if (root->right != nullptr) {
			rightLength = minDepth(root->right);
		}
		return 1 + min(leftLength, rightLength);
	}
};

void solution111();
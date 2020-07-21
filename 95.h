#pragma once
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0),left(nullptr),right(nullptr){}
	TreeNode(int x): val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution95 {
public:
	vector<TreeNode*> generateTrees(int start, int end) {
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> allTrees;
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
			vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
			for (auto& left : leftTrees) {
				for (auto& right : rightTrees) {
					TreeNode* currTree = new TreeNode(i);
					currTree->left = left;
					currTree->right = right;
					allTrees.emplace_back(currTree);
				}
			}
		}
		return allTrees;
	}
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return {};
		}
		return generateTrees(1,n);
	}
};

void solution95();

//笔记
//1.NULL在C++中就是0，这是因为在C++中void* 类型是不允许隐式转换成其他类型的,
//  nullptr，可以保证在任何情况下都代表空指针
//2.vector花括号里面一个数初始化（赋值）表示赋一个值。
//  而圆括号里面一个数表示用几个相同元素初始化。
//3.auto遍历容器的方法
//4.emplace_back和push_back区别
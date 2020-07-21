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

//�ʼ�
//1.NULL��C++�о���0��������Ϊ��C++��void* �����ǲ�������ʽת�����������͵�,
//  nullptr�����Ա�֤���κ�����¶������ָ��
//2.vector����������һ������ʼ������ֵ����ʾ��һ��ֵ��
//  ��Բ��������һ������ʾ�ü�����ͬԪ�س�ʼ����
//3.auto���������ķ���
//4.emplace_back��push_back����
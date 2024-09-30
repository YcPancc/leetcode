/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
	}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  private:
	TreeNode *process(const vector<int> &preorder, int preOrderBegin, int preOrderEnd, const vector<int> &inorder, int inOrderBegin, int inOrderEnd) {
		if (preOrderBegin == preOrderEnd)
			return nullptr;
		int rootValue = preorder[preOrderBegin];
		TreeNode *root = new TreeNode(rootValue);
		if (preOrderBegin == preOrderEnd - 1)
			return root;
		int rootIndex;
		for (rootIndex = inOrderBegin; rootIndex < inOrderEnd; rootIndex++)
			if (inorder[rootIndex] == rootValue)
				break;
		int leftInOrderBegin = inOrderBegin;
		int leftInOrderEnd = rootIndex;
		int rightInOrderBegin = rootIndex + 1;
		int rightInOrderEnd = inOrderEnd;

		int leftPreOrderBegin = preOrderBegin + 1;
		int leftPreOrderEnd = leftPreOrderBegin + rootIndex - inOrderBegin;
		int rightPreOrderBegin = leftPreOrderBegin + rootIndex - inOrderBegin;
		int rightPreOrderEnd = preOrderEnd;

		root->left = process(preorder, leftPreOrderBegin, leftPreOrderEnd, inorder, leftInOrderBegin, leftInOrderEnd);
		root->right = process(preorder, rightPreOrderBegin, rightPreOrderEnd, inorder, rightInOrderBegin, rightInOrderEnd);

		return root;
	}

  public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty())
			return nullptr;
		return process(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

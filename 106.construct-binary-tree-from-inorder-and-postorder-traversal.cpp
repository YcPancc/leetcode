/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <vector>
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
	TreeNode *process(vector<int> inorder, int inorderBegin, int inorderEnd, vector<int> postorder, int postorderBegin, int postorderEnd) {
		if (inorderBegin == inorderEnd)
			return nullptr;
		int rootValue = postorder[postorderEnd - 1];
		TreeNode *root = new TreeNode(rootValue);
		if (postorderBegin == postorderEnd - 1)
			return root;
		int rootIndex;
		for (rootIndex = inorderBegin; rootIndex < inorderEnd; rootIndex++)
			if (inorder[rootIndex] == rootValue)
				break;
		int leftInOrderBegin = inorderBegin;
		int leftInOrderEnd = rootIndex;
		int rightInOrderBegin = rootIndex + 1;
		int rightInOrderEnd = inorderEnd;

		int leftPostOrderBegin = postorderBegin;
		int leftPostOrderEnd = postorderBegin - inorderBegin + rootIndex;
		int rightPostOrderBegin = postorderBegin - inorderBegin + rootIndex;
		int rightPostOrderEnd = postorderEnd - 1;

		root->left = process(inorder, leftInOrderBegin, leftInOrderEnd, postorder, leftPostOrderBegin, leftPostOrderEnd);
		root->right = process(inorder, rightInOrderBegin, rightInOrderEnd, postorder, rightPostOrderBegin, rightPostOrderEnd);

		return root;
	}

  public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty())
			return nullptr;
		TreeNode *root = process(inorder, 0, inorder.size(), postorder, 0, postorder.size());
		return root;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

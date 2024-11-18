/*
 * @lc app=leetcode.cn id=669 lang=cpp
 * @lcpr version=30204
 *
 * [669] 修剪二叉搜索树
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
	TreeNode *process(TreeNode *node, const int &low, const int &high) {
		if (!node)
			return nullptr;
		if (node->val > high) {
			return process(node->left, low, high);
		} else if (node->val < low) {
			return process(node->right, low, high);
		} else {
			node->left = process(node->left, low, high);
			node->right = process(node->right, low, high);
			return node;
		}
	}

  public:
	TreeNode *trimBST(TreeNode *root, int low, int high) {
		return process(root, low, high);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,0,4,null,2,null,null,1]\n1\n3\n
// @lcpr case=end

 */

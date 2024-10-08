/*
 * @lc app=leetcode.cn id=669 lang=cpp
 * @lcpr version=30204
 *
 * [669] 修剪二叉搜索树
 */

// @lcpr-template-start
#include <bits/stdc++.h>
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
  public:
	TreeNode *trimBST(TreeNode *root, int low, int high) {  
		if (!root)
			return nullptr;
		if (root->val < low) {
			TreeNode *right = trimBST(root->right, low, high);
			return right;
		}
		if (root->val > high) {
			TreeNode *left = trimBST(root->left, low, high);
			return left;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
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

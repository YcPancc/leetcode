/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
	bool compare(TreeNode *left, TreeNode *right) {
		if (!left && right)
			return false;
		else if (left && !right)
			return false;
		else if (!left && !right)
			return true;
		else if (left->val != right->val)
			return false;
		return compare(left->left, right->right) && compare(left->right, right->left);
	}

  public:
	bool isSymmetric(TreeNode *root) {
		if (!root)
			return true;
		return compare(root->left, root->right);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

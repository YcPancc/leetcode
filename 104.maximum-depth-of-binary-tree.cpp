/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] 二叉树的最大深度
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
	int getMax(TreeNode *node) {
		int left = 1, right = 1;
		if (node->left)
			left = getMax(node->left) + 1;
		if (node->right)
			right = getMax(node->right) + 1;
		return max(left, right);
	}

  public:
	int maxDepth(TreeNode *root) {
		if (!root)
			return 0;
		return getMax(root);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

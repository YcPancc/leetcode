/*
 * @lc app=leetcode.cn id=538 lang=cpp
 * @lcpr version=30204
 *
 * [538] 把二叉搜索树转换为累加树
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
  private:
	int pre = INT_MIN;
	void process(TreeNode *cur) {
		if (cur->right)
			process(cur->right);
		if (pre != INT_MIN)
			cur->val = cur->val + pre;
		pre = cur->val;
		if (cur->left)
			process(cur->left);
		return;
	}

  public:
	TreeNode *convertBST(TreeNode *root) {
		if (!root)
			return nullptr;
		process(root);
		return root;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n
// @lcpr case=end

 */

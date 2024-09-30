/*
 * @lc app=leetcode.cn id=701 lang=cpp
 * @lcpr version=30204
 *
 * [701] 二叉搜索树中的插入操作
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
	void process(TreeNode *cur, int val) {
		if (cur->val > val) {
			if (!cur->left)
				cur->left = new TreeNode(val);
			else
				process(cur->left, val);
		} else {
			if (!cur->right)
				cur->right = new TreeNode(val);
			else
				process(cur->right, val);
		}
		return;
	}

  public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		if (!root)
			return new TreeNode(val);
		process(root, val);
		return root;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [40,20,60,10,30,50,70]\n25\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3,null,null,null,null,null,null]\n5\n
// @lcpr case=end

 */

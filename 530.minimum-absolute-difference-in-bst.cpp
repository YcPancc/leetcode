/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30204
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <climits>
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
	int min = 10e5 + 1;
	TreeNode *pre = nullptr;
	void process(TreeNode *node) {
		if (!node)
			return;
		process(node->left);
		if (pre)
			min = min > node->val - pre->val ? node->val - pre->val : min;
		pre = node;
		process(node->right);
	}

  public:
	int getMinimumDifference(TreeNode *root) {
		process(root);
		return min;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

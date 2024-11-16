/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] 二叉搜索树中的众数
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
	int maxCount = 0;
	int count = 0;
	TreeNode *pre = nullptr;
	vector<int> result;
	void process(TreeNode *node) {
		if (!node)
			return;
		process(node->left);
		if (!pre)
			count = 1;
		else if (pre->val == node->val)
			count++;
		else
			count = 1;
		pre = node;
		if (count > maxCount) {
			maxCount = count;
			result.clear();
			result.push_back(node->val);
		} else if (count == maxCount) {
			result.push_back(node->val);
		}
		process(node->right);
		return;
	}

  public:
	vector<int> findMode(TreeNode *root) {
		process(root);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

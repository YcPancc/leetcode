/*
 * @lc app=leetcode.cn id=968 lang=cpp
 * @lcpr version=30204
 *
 * [968] 监控二叉树
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
	int result = 0;
	int backtracking(TreeNode *node) {
		if (!node)
			return 2;
		int left = backtracking(node->left);
		int right = backtracking(node->right);
		if (left == 2 && right == 2)
			return 0;
		else if (left == 0 || right == 0) {
			result++;
			return 1;
		} else
			return 2;
	}

  public:
	int minCameraCover(TreeNode *root) {
		result = 0;
		if (backtracking(root) == 0)
			result++;
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [0,0,null,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,null,0,null,0,null,null,0]\n
// @lcpr case=end

 */

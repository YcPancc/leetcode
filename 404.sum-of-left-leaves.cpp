/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30204
 *
 * [404] 左叶子之和
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
	void getSum(TreeNode *cur, int &sum, bool isleft) {
		if (isleft && !cur->left && !cur->right)
			sum += cur->val;
		if (cur->left)
			getSum(cur->left, sum, true);
		if (cur->right)
			getSum(cur->right, sum, false);
	}

  public:
	int sumOfLeftLeaves(TreeNode *root) {
		if (!root)
			return 0;
		int sum = 0;
		if (root->left)
			getSum(root->left, sum, true);
		if (root->right)
			getSum(root->right, sum, false);
		return sum;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

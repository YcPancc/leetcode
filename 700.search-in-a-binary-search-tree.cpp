/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=30204
 *
 * [700] 二叉搜索树中的搜索
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
	TreeNode *process(TreeNode *node, const int &val) {
		if (!node)
			return nullptr;
		else {
			if (node->val == val)
				return node;
			else if (node->val > val)
				return process(node->left, val);
			else
				return process(node->right, val);
		}
	}

  public:
	TreeNode *searchBST(TreeNode *root, int val) {
		return process(root, val);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

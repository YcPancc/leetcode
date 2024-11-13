/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30204
 *
 * [257] 二叉树的所有路径
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <string>
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
	void process(TreeNode *node, vector<string> &result, const string &s) {
		if (node->left)
			process(node->left, result, s + "->" + to_string(node->left->val));
		if (node->right)
			process(node->right, result, s + "->" + to_string(node->right->val));
		if (!node->left && !node->right) {
			result.push_back(s);
		}
	}

  public:
	vector<string> binaryTreePaths(TreeNode *root) {
		if (!root)
			return {};
		vector<string> result;
		process(root, result, to_string(root->val));
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

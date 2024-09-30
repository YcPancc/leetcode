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
	void process(TreeNode *cur, vector<string> &result, const string &parent) {
		if (!cur->left && !cur->right) {
			result.push_back(parent);
		}
		string tmp = parent + "->";
		if (cur->left)
			process(cur->left, result, tmp + to_string(cur->left->val));
		if (cur->right)
			process(cur->right, result, tmp + to_string(cur->right->val));
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

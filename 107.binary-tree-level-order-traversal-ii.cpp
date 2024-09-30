/*
 * @lc app=leetcode.cn id=107 lang=cpp
 * @lcpr version=30204
 *
 * [107] 二叉树的层序遍历 II
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
	void process(vector<TreeNode *> vec, vector<vector<int>> &result) {
		if (vec.empty())
			return;
		vector<TreeNode *> next;
		vector<int> tmp;
		for (const TreeNode *node : vec) {
			if (node->left)
				next.push_back(node->left);
			if (node->right)
				next.push_back(node->right);
			tmp.push_back(node->val);
		}
		process(next, result);
		result.push_back(tmp);
	}

  public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		if (!root)
			return {};
		vector<vector<int>> result;
		vector<TreeNode *> vec = {root};
		process(vec, result);
		return result;
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

// @lcpr case=start
// []\n
// @lcpr case=end

 */

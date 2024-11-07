/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30204
 *
 * [144] 二叉树的前序遍历
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
	// 递归法
	void recursion(vector<int> &result, TreeNode *node) {
		if (!node)
			return;
		result.push_back(node->val);
		recursion(result, node->left);
		recursion(result, node->right);
	}
	// 迭代法
	void iteration(vector<int> &result, TreeNode *node) {
		if (!node)
			return;
		stack<TreeNode *> st;
		st.push(node);
		while (!st.empty()) {
			TreeNode *cur = st.top();
			result.push_back(cur->val);
			st.pop();
			if (cur->right)
				st.push(cur->right);
			if (cur->left)
				st.push(cur->left);
		}
	}

  public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		iteration(result, root);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

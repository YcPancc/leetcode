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
	void traversal_recursion(const TreeNode *cur, vector<int> &result) {
		if (cur == nullptr)
			return;
		result.push_back(cur->val);
		traversal_recursion(cur->left, result);
		traversal_recursion(cur->right, result);
	}

	// 迭代法
	void traversal_iteration(TreeNode *cur, vector<int> &result) {
		stack<TreeNode *> st;
		if (cur == nullptr)
			return;
		st.push(cur);
		while (!st.empty()) {
			TreeNode *tmp = st.top();
			st.pop();
			if (tmp->right)
				st.push(tmp->right);
			if (tmp->left)
				st.push(tmp->left);
			result.push_back(tmp->val);
		}
	}

  public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		traversal_iteration(root, result);
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

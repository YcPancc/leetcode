/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <vector>
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
	void traversal_recursion(const TreeNode *cur, vector<int> &vec) {
		if (cur == nullptr)
			return;
		traversal_recursion(cur->left, vec);
		vec.push_back(cur->val);
		traversal_recursion(cur->right, vec);
	}

	// 迭代法
	void traversal_iteration(TreeNode *cur, vector<int> &vec) {
		stack<TreeNode *> st;
		while (cur != nullptr || !st.empty()) {
			if (cur != nullptr) {
				st.push(cur);
				cur = cur->left;
			} else {
				cur = st.top();
				st.pop();
				vec.push_back(cur->val);
				cur = cur->right;
			}
		}
	}

  public:
	vector<int> inorderTraversal(TreeNode *root) {
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
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

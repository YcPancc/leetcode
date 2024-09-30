/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30204
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lcpr-template-start
#include <bits/stdc++.h>
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
  public:
	TreeNode *deleteNode(TreeNode *root, int key) {
		if (!root)
			return nullptr;
		if (root->val == key) {
			if (!root->left && !root->right) {
				delete root;
				return nullptr;
			} else if (!root->left) {
				TreeNode *tmp = root->right;
				delete root;
				return tmp;
			} else if (!root->right) {
				TreeNode *tmp = root->left;
				delete root;
				return tmp;
			} else {
				TreeNode *cur = root->right;
				while (cur->left) {
					cur = cur->left;
				}
				cur->left = root->left;
				TreeNode *tmp = root;
				root = root->right;
				delete tmp;
				return root;
			}
		}
		if (root->val > key)
			root->left = deleteNode(root->left, key);
		if (root->val < key)
			root->right = deleteNode(root->right, key);
		return root;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

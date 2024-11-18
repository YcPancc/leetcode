/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30204
 *
 * [450] 删除二叉搜索树中的节点
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
	TreeNode *process(TreeNode *node, const int &key) {
		if (!node)
			return nullptr;
		if (node->val == key) {
			if (!node->left && !node->right) {
				delete node;
				return nullptr;
			} else if (node->left && !node->right) {
				TreeNode *result = node->left;
				delete node;
				return result;
			} else if (!node->left && node->right) {
				TreeNode *result = node->right;
				delete node;
				return result;
			} else {
				TreeNode *cur = node->right;
				while (cur->left) {
					cur = cur->left;
				}
				cur->left = node->left;
				TreeNode *tmp = node;
				node = node->right;
				delete tmp;
				return node;
			}
		}
		if (node->val > key)
			node->left = process(node->left, key);
		if (node->val < key)
			node->right = process(node->right, key);
		return node;
	}

  public:
	TreeNode *deleteNode(TreeNode *root, int key) {
		return process(root, key);
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

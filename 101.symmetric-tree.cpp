/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
  public:
	bool isSymmetric(TreeNode *root) {
		if (!root || !root->left && !root->right)
			return true;
		queue<TreeNode *> left_qu;
		queue<TreeNode *> right_qu;
		int l_lens, r_lens;
		if (root->left && root->right || root->left == nullptr && root->right == nullptr) {
			if (root->left->val != root->right->val) {
				return false;
			}
			left_qu.push(root->left);
			right_qu.push(root->right);
		} else {
			return false;
		}
		while (!left_qu.empty() && !right_qu.empty()) {
			TreeNode *l;
			TreeNode *r;
			l_lens = left_qu.size();
			r_lens = right_qu.size();
			if (l_lens != r_lens)
				return false;
			while (l_lens-- && r_lens-- && l_lens == r_lens) {
				l = left_qu.front();
				r = right_qu.front();
				left_qu.pop();
				right_qu.pop();
				if (l->val != r->val)
					return false;
				if (l->left && r->right) {
					left_qu.push(l->left);
					right_qu.push(r->right);
				} else if (l->left == nullptr && r->right != nullptr) {
					return false;
				} else if (l->left != nullptr && r->right == nullptr) {
					return false;
				}

				if (l->right && r->left) {
					left_qu.push(l->right);
					right_qu.push(r->left);
				} else if (l->right == nullptr && r->left != nullptr) {
					return false;
				} else if (l->right != nullptr && r->left == nullptr) {
					return false;
				}
			}
		}
		return true;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

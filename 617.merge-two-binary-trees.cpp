/*
 * @lc app=leetcode.cn id=617 lang=cpp
 * @lcpr version=30204
 *
 * [617] 合并二叉树
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
	TreeNode *process(TreeNode *cur1, TreeNode *cur2) {
		if (!cur1)
			return cur2;
		if (!cur2)
			return cur1;
		TreeNode *root = new TreeNode(cur1->val + cur2->val);
		root->left = process(cur1->left, cur2->left);
		root->right = process(cur1->right, cur2->right);
		return root;
	}

  public:
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
		return process(root1, root2);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,5]\n[2,1,3,null,4,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1,2]\n
// @lcpr case=end

 */

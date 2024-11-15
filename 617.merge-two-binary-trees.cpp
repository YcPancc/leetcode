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
	TreeNode *process(TreeNode *node1, TreeNode *node2) {
		if (!node2)
			return node1;
		if (!node1)
			return node2;
		node1->val += node2->val;
		node1->left = process(node1->left, node2->left);
		node1->right = process(node1->right, node2->right);
		return node1;
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

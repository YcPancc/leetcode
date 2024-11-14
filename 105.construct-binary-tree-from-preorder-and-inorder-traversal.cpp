/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
	TreeNode *process(const vector<int> &preorder, const vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight) {
		if (preLeft > preRight)
			return nullptr;
		int top = preorder[preLeft];
		int site = inLeft;
		for (; site <= inRight; site++) {
			if (inorder[site] == top)
				break;
		}
		TreeNode *node = new TreeNode(top);
		node->left = process(preorder, inorder, preLeft + 1, preLeft + site - inLeft, inLeft, site - 1);
		node->right = process(preorder, inorder, preLeft + site - inLeft + 1, preRight, site + 1, inRight);
		return node;
	}

  public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return process(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

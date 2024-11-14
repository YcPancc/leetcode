/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 */
class Solution {
  private:
	TreeNode *process(const vector<int> &inorder, const vector<int> &postorder, const int Inleft, const int Inright, const int Postleft, const int Postright) {
		if (Inright - Inleft < 0)
			return nullptr;
		int top = postorder[Postright];
		int site = Inleft;
		for (; site <= Inright; site++) {
			if (inorder[site] == top)
				break;
		}
		TreeNode *head = new TreeNode(top);
		head->left = process(inorder, postorder, Inleft, site - 1, Postleft, Postleft + site - Inleft - 1);
		head->right = process(inorder, postorder, site + 1, Inright, Postleft + site - Inleft, Postright - 1);
		return head;
	}

  public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return process(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

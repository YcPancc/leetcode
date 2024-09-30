/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30204
 *
 * [108] 将有序数组转换为二叉搜索树
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
	TreeNode *process(const std::vector<int> &nums, const int &l, const int &r) {
		if (l > r)
			return nullptr;
		if (l == r)
			return new TreeNode(nums[l]);
		int mid = (l + r) >> 1;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = process(nums, l, mid - 1);
		root->right = process(nums, mid + 1, r);
		return root;
	}

  public:
	TreeNode *sortedArrayToBST(std::vector<int> &nums) {
		int lens = nums.size();
		return process(nums, 0, lens - 1);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

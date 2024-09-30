/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
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
	TreeNode *process(const vector<int> &nums, int l, int r) {
		if (l == r)
			return nullptr;
		int max = nums[l];
		int maxIndex = l;
		for (int i = l + 1; i < r; i++) {
			if (nums[i] > max) {
				maxIndex = i;
				max = nums[i];
			}
		}
		TreeNode *maxPtr = new TreeNode(max);
		maxPtr->left = process(nums, l, maxIndex);
		maxPtr->right = process(nums, maxIndex + 1, r);
		return maxPtr;
	}

  public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		return process(nums, 0, nums.size());
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

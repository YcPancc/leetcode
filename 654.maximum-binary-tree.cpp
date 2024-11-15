/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <climits>
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
	TreeNode *process(const vector<int> &nums, const int &left, const int &right) {
		if (left > right)
			return nullptr;
		int max = INT_MIN;
		int location = -1;
		for (int i = left; i <= right; i++) {
			location = max > nums[i] ? location : i;
			max = max > nums[i] ? max : nums[i];
		}
		TreeNode *node = new TreeNode(max);
		node->left = process(nums, left, location - 1);
		node->right = process(nums, location + 1, right);
		return node;
	}

  public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		return process(nums, 0, nums.size() - 1);
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

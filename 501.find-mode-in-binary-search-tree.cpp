/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] 二叉搜索树中的众数
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
	vector<int> result;
	int maxCount = 0;
	int count = 0;
	TreeNode *pre;

	void process(TreeNode *cur) {
		if (!cur)
			return;
		process(cur->left);
		if (pre) {
			if (pre->val == cur->val)
				count++;
			else
				count = 1;
		} else {
			count++;
		}
		pre = cur;
		if (count > maxCount) {
			maxCount = count;
			result.clear();
			result.push_back(cur->val);
		} else if (count == maxCount) {
			result.push_back(cur->val);
		}
		process(cur->right);
	}

  public:
	vector<int> findMode(TreeNode *root) {
		process(root);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

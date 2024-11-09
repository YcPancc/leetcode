/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] 二叉树的层序遍历
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
	vector<vector<int>> levelOrder(TreeNode *root) {
		if (!root)
			return {};
		queue<TreeNode *> qu;
		qu.push(root);
		vector<vector<int>> result;
		while (!qu.empty()) {
			int lens = qu.size();
			vector<int> arr(lens);
			for (int i = 0; i < lens; i++) {
				TreeNode *cur = qu.front();
				qu.pop();
				arr[i] = cur->val;
				if (cur->left)
					qu.push(cur->left);
				if (cur->right)
					qu.push(cur->right);
			}
			result.push_back(arr);
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

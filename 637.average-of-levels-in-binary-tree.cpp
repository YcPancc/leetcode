/*
 * @lc app=leetcode.cn id=637 lang=cpp
 * @lcpr version=30204
 *
 * [637] 二叉树的层平均值
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
	vector<double> averageOfLevels(TreeNode *root) {
		if (!root)
			return {};
		vector<double> result;
		queue<TreeNode *> qu;
		qu.push(root);
		int lens;
		while (!qu.empty()) {
			lens = qu.size();
			double len = lens;
			TreeNode *node;
			vector<double> vec;
			double nums = 0;
			while (lens--) {
				node = qu.front();
				qu.pop();
				nums += node->val;
				if (node->left)
					qu.push(node->left);
				if (node->right)
					qu.push(node->right);
			}
			result.push_back(nums / len);
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
// [3,9,20,15,7]\n
// @lcpr case=end

 */

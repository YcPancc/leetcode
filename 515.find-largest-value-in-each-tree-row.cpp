/*
 * @lc app=leetcode.cn id=515 lang=cpp
 * @lcpr version=30204
 *
 * [515] 在每个树行中找最大值
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
  public:
	vector<int> largestValues(TreeNode *root) {
		if (!root)
			return {};
		vector<int> result;
		queue<TreeNode *> qu;
		qu.push(root);
		while (!qu.empty()) {
			int lens = qu.size();
			int max = INT_MIN;
			for (int i = 0; i < lens; i++) {
				TreeNode *cur = qu.front();
				qu.pop();
				max = max < cur->val ? cur->val : max;
				if (cur->left)
					qu.push(cur->left);
				if (cur->right)
					qu.push(cur->right);
			}
			result.push_back(max);
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

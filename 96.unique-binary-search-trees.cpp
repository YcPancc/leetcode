/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30204
 *
 * [96] 不同的二叉搜索树
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int climbStairs(int n) {
		if (n <= 2) {
			return n;
		}
		int dp[3];
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			int sum = dp[1] + dp[2];
			dp[1] = dp[2];
			dp[2] = sum;
		}
		return dp[2];
	}
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30204
 *
 * [746] 使用最小花费爬楼梯
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int minCostClimbingStairs(vector<int> &cost) {
		int lens = cost.size();
		int dp[3];
		dp[1] = cost[0];
		dp[2] = cost[1];
		for (int i = 2; i < lens; i++) {
			int sum = cost[i] + min(dp[1], dp[2]);
			dp[1] = dp[2];
			dp[2] = sum;
		}
		return min(dp[1], dp[2]);
	}
};
// @lc code=end

/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

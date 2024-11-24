/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30204
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++) {
			result += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

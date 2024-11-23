/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int maxSubArray(vector<int> &nums) {
		int sum = 0;
		int max = -10e4 - 1;
		for (int i = 0; i < nums.size(); i++) {
			if (sum < 0)
				sum = 0;
			sum += nums[i];
			max = max < sum ? sum : max;
		}
		return max;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

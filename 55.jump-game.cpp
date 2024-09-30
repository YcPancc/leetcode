/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30204
 *
 * [55] 跳跃游戏
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool canJump(vector<int> &nums) {
		if (nums.size() == 1)
			return true;
		int max = nums[0];
		for (int i = 0; i <= max && i < nums.size(); i++) {
			if (nums[i] + i > max) {
				max = nums[i] + i;
			}
			if (max >= nums.size() - 1) {
				return true;
			}
		}
		return false;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

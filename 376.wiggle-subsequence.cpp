/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30204
 *
 * [376] 摆动序列
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int wiggleMaxLength(vector<int> &nums) {
		if (nums.size() <= 1)
			return nums.size();
		int preDiff = 0;
		int nowDiff = 0;
		int result = 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			nowDiff = nums[i + 1] - nums[i];
			if (preDiff >= 0 && nowDiff < 0 || preDiff <= 0 && nowDiff > 0) {
				result += 1;
				preDiff = nowDiff;
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */

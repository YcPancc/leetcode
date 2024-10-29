/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <climits>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int result = INT_MAX;
		int fast = 0, slow = 0;
		int sum = 0, lens = nums.size();
		for (; fast < lens; fast++) {
			sum += nums[fast];
			while (sum >= target) {
				if (fast - slow + 1 < result) {
					result = fast - slow + 1;
				}
				sum -= nums[slow];
				slow++;
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

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
		int lens = nums.size();
		int l = 0, r = 0;
		int sum = 0;
		int min_lens = INT_MAX;
		while (r < lens) {
			sum += nums[r];
			while (sum >= target) {
				min_lens = (r - l + 1) > min_lens ? min_lens : (r - l + 1);
				sum -= nums[l++];
			}
			r++;
		}
		return min_lens == INT_MAX ? 0 : min_lens;
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

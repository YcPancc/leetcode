/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int lens = nums.size() - 1;
		if (nums[0] > 0 && nums[lens] < 0)
			return {};
		vector<vector<int>> result;
		for (int i = 0; i < lens - 1; i++) {
			if (nums[i] > 0)
				return result;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1, r = lens;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] > 0) {
					r--;
				} else if (nums[i] + nums[l] + nums[r] < 0) {
					l++;
				} else {
					result.push_back(vector<int>{nums[i], nums[l], nums[r]});
					while (l < r && nums[r] == nums[r - 1])
						r--;
					while (l < r && nums[l] == nums[l + 1])
						l++;
					r--;
					l++;
				}
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

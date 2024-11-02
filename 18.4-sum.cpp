/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		int lens = nums.size();
		vector<vector<int>> result;
		for (int i = 0; i < lens - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < lens - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int l = j + 1, r = lens - 1;
				while (l < r) {
					if ((long)(nums[i]) + nums[j] + nums[l] + nums[r] > target) {
						r--;
					} else if ((long)(nums[i]) + nums[j] + nums[l] + nums[r] < target) {
						l++;
					} else {
						result.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
						while (l < r && nums[l] == nums[l + 1]) {
							l++;
						}
						while (l < r && nums[r] == nums[r - 1]) {
							r--;
						}
						l++;
						r--;
					}
				}
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

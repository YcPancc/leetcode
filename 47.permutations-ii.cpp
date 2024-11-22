/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;
	vector<int> vec;
	void backtracking(const vector<int> &nums, vector<bool> used) {
		if (vec.size() == nums.size()) {
			result.push_back(vec);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}
			if (!used[i]) {
				used[i] = true;
				vec.push_back(nums[i]);
				backtracking(nums, used);
				vec.pop_back();
				used[i] = false;
			}
		}
	}

  public:
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

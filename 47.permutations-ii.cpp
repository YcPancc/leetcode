/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30204
 *
 * [47] 全排列 II
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<int> path;
	vector<vector<int>> result;
	void backtracking(const vector<int> &nums, vector<bool> &used) {
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
				continue;
			}
			if (!used[i]) {
				used[i] = 1;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = 0;
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

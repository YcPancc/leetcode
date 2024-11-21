/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
 *
 * [90] 子集 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;
	vector<int> arr;
	void backtracking(const vector<int> &nums, int start, vector<bool> used) {
		result.push_back(arr);
		if (start >= nums.size())
			return;
		for (int i = start; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
				continue;
			arr.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, i + 1, used);
			used[i] = false;
			arr.pop_back();
		}
	}

  public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		backtracking(nums, 0, used);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

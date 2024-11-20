/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
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
	int sum = 0;
	void backtracking(vector<int> &nums, int pos, int target, vector<bool> &used) {
		if (sum > target) {
			return;
		} else if (sum == target) {
			result.push_back(arr);
			return;
		}
		for (int i = pos; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
				continue;
			sum += nums[i];
			arr.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, i + 1, target, used);
			used[i] = false;
			arr.pop_back();
			sum -= nums[i];
		}
	}

  public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<bool> used(candidates.size());
		backtracking(candidates, 0, target, used);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
			if (used[i]) {
				continue;
			} else {
				vec.push_back(nums[i]);
				used[i] = true;
				backtracking(nums, used);
				used[i] = false;
				vec.pop_back();
			}
		}
	}

  public:
	vector<vector<int>> permute(vector<int> &nums) {
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

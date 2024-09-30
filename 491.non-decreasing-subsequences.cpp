/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=30204
 *
 * [491] 非递减子序列
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;
	vector<int> path;

	void backtracking(const vector<int> &nums, const int &cur) {
		if (path.size() >= 2)
			result.push_back(path);
		int used[201] = {0};
		for (int i = cur; i < nums.size(); i++) {
			if ((!path.empty() && path.back() > nums[i]) || used[100 + nums[i]] == 1) {
				continue;
			}
			used[100 + nums[i]] = 1;
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

  public:
	vector<vector<int>> findSubsequences(vector<int> &nums) {
		backtracking(nums, 0);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */

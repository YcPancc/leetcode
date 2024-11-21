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
	vector<int> vec;
	void backtracking(const vector<int> &nums, const int &start) {
		if (vec.size() > 1)
			result.push_back(vec);
		unordered_set<int> uset;
		for (int i = start; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end() || !vec.empty() && nums[i] < vec.back())
				continue;
			uset.insert(nums[i]);
			vec.push_back(nums[i]);
			backtracking(nums, i + 1);
			vec.pop_back();
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

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
	void backtracking(const vector<int> &nums, int start) {
		result.push_back(arr);
		if (start >= nums.size()) {
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			arr.push_back(nums[i]);
			backtracking(nums, i + 1);
			arr.pop_back();
		}
	}

  public:
	vector<vector<int>> subsets(vector<int> &nums) {
		backtracking(nums, 0);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

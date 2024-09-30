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
	vector<int> path;
	void backtracking(const vector<int> &vec, const int &site) {
		result.push_back(path);
		if (site >= vec.size()) {
			return;
		}
		for (int i = site; i < vec.size(); i++) {
			path.push_back(vec[i]);
			backtracking(vec, i + 1);
			path.pop_back();
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

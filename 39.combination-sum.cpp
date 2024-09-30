/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	int sum;
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(const int &cur, const int &target, const vector<int> &vec, const int &lens) {
		if (sum > target)
			return;
		if (sum == target) {
			result.push_back(path);
		}
		for (int i = cur; i < lens; i++) {
			sum += vec[i];
			path.push_back(vec[i]);
			backtracking(i, target, vec, lens);
			sum -= vec[i];
			path.pop_back();
		}
	}

  public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		int lens = candidates.size();
		backtracking(0, target, candidates, lens);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

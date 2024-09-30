/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30204
 *
 * [40] 组合总和 II
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;
	int sum = 0;
	vector<int> path;
	void backtracking(const int &start, const int &target, const vector<int> &vec, const int &lens, vector<bool> used) {
		if (sum > target)
			return;
		if (sum == target) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < lens; i++) {
			if (i > 0 && vec[i] == vec[i - 1] && used[i - 1] == false)
				continue;
			sum += vec[i];
			path.push_back(vec[i]);
			used[i] = true;
			backtracking(i + 1, target, vec, lens, used);
			sum -= vec[i];
			path.pop_back();
			used[i] = false;
		}
	}

  public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<bool> used(candidates.size(), false);
		backtracking(0, target, candidates, candidates.size(), used);
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

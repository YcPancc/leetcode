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
	int sum = 0;
	vector<vector<int>> result;
	vector<int> arr;
	void backtracking(const vector<int> &vec, const int &target, int pos) {
		if (sum > target)
			return;
		else if (sum == target) {
			result.push_back(arr);
			return;
		}
		for (int i = pos; i < vec.size(); i++) {
			arr.push_back(vec[i]);
			sum += vec[i];
			backtracking(vec, target, i);
			sum -= vec[i];
			arr.pop_back();
		}
	}

  public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		backtracking(candidates, target, 0);
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

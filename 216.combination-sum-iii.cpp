/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30204
 *
 * [216] 组合总和 III
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;
	int sum = 0;
	void backtracking(vector<int> &vec, const int &start, const int &target, const int &lens) {
		if (vec.size() == lens) {
			if (sum == target) {
				result.push_back(vec);
			}
			return;
		}
		for (int i = start; i <= 9 - (lens - vec.size()) + 1; i++) {
			vec.push_back(i);
			sum += i;
			backtracking(vec, i + 1, target, lens);
			sum -= i;
			vec.pop_back();
		}
	}

  public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> vec;
		backtracking(vec, 1, n, k);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

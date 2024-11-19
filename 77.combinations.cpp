/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<int>> result;

	void backtracking(vector<int> &vec, const int &start, const int &need, const int &end, const int &lens) {
		if (vec.size() == lens) {
			result.push_back(vec);
			return;
		}
		for (int i = start; i <= end - need; i++) {
			vec.push_back(i);
			backtracking(vec, i + 1, need - 1, end, lens);
			vec.pop_back();
		}
	}

  public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> vec;
		backtracking(vec, 1, k - 1, n, k);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

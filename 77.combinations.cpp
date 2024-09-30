/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
 */

// @lcpr-template-start
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
		return;
	}

  public:
	std::vector<std::vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
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

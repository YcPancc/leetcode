/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30204
 *
 * [216] 组合总和 III
 */

// @lcpr-template-start
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	int sum = 0;
	void process(int start, int n, int k) {
		if (sum > n)
			return;
		if (path.size() == k) {
			if (sum == n)
				result.push_back(path);
			return;
		}
		for (int i = start; i <= 9 - k + path.size() + 1; i++) {
			path.push_back(i);
			sum += i;
			process(i + 1, n, k);
			sum -= i;
			path.pop_back();
		}
		return;
	}

  public:
	std::vector<std::vector<int>> combinationSum3(int k, int n) {
		process(1, n, k);
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

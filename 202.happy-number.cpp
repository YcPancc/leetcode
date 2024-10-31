/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐数
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool isHappy(int n) {
		unordered_set<int> set;
		while (set.find(n) == set.end()) {
			if (n == 1)
				return true;
			set.insert(n);
			n = process(n);
		}
		return false;
	}
	int process(int num) {
		int result = 0;
		while (num) {
			int tmp = num % 10;
			num /= 10;
			result += tmp * tmp;
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

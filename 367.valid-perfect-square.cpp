/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30204
 *
 * [367] 有效的完全平方数
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool isPerfectSquare(int num) {
		int l = 0, r = num;
		int mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if ((long long)mid * mid < num)
				l = mid + 1;
			else if ((long long)mid * mid > num)
				r = mid - 1;
			else
				return true;
		}
		return false;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */

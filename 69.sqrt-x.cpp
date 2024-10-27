/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 的平方根
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int mySqrt(int x) {
		long l = 0, r = x;
		long mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
				return mid;
			} else if (mid * mid < x) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return 0;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

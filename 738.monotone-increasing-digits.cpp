/*
 * @lc app=leetcode.cn id=738 lang=cpp
 * @lcpr version=30204
 *
 * [738] 单调递增的数字
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int monotoneIncreasingDigits(int n) {
		string n_str = to_string(n);
		int flag;
		for (int i = n_str.size() - 1; i > 0; i--) {
			if (n_str[i - 1] > n_str[i]) {
				flag = i;
				n_str[i - 1]--;
			}
		}
		for (int i = flag; i < n_str.size(); i++) {
			n_str[i] = '9';
		}
		return stoi(n_str);
	}
};
// @lc code=end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1234\n
// @lcpr case=end

// @lcpr case=start
// 332\n
// @lcpr case=end

 */

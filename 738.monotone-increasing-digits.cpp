/*
 * @lc app=leetcode.cn id=738 lang=cpp
 * @lcpr version=30204
 *
 * [738] 单调递增的数字
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int monotoneIncreasingDigits(int n) {
		string str_num = to_string(n);
		int pos = str_num.size();
		for (int i = str_num.size() - 1; i > 0; i--) {
			if (str_num[i - 1] > str_num[i]) {
				pos = i;
				str_num[i - 1]--;
			}
		}
		for (int i = pos; i < str_num.size(); i++) {
			str_num[i] = '9';
		}
		return stoi(str_num);
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

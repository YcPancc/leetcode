/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30204
 *
 * [344] 反转字符串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	void reverseString(vector<char> &s) {
		int l = 0, r = s.size() - 1;
		char ch;
		while (l < r) {
			ch = s[l];
			s[l] = s[r];
			s[r] = ch;
			l++;
			r--;
		}
	}
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

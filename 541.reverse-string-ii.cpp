/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	string reverseStr(string s, int k) {
		int lens = s.size();
		if (lens == 1)
			return s;
		int l, r;
		int i;
		for (i = 0; i + 2 * k - 1 < lens; i += 2 * k) {
			l = i;
			r = i + k - 1;
			while (l < r) {
				char tmp = s[l];
				s[l] = s[r];
				s[r] = tmp;
				l++;
				r--;
			}
		}
		l = i;
		r = i + k - 1 > lens - 1 ? lens - 1 : i + k - 1;
		while (l < r) {
			char tmp = s[l];
			s[l] = s[r];
			s[r] = tmp;
			l++;
			r--;
		}
		return s;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */

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
		for (int i = 0; i < lens; i += 2 * k) {
			if (i + k > lens) {
				reverse(s, i, lens - 1);
			} else {
				reverse(s, i, i + k - 1);
			}
		}
		return s;
	}
	void reverse(string &s, int l, int r) {
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
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */

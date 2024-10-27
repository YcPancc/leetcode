/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=30204
 *
 * [844] 比较含退格的字符串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool backspaceCompare(string s, string t) {
		string sstr, tstr;
		for (char ch : s) {
			if (ch != '#') {
				sstr.push_back(ch);
			} else {
				if (!sstr.empty())
					sstr.pop_back();
			}
		}

		for (char ch : t) {
			if (ch != '#') {
				tstr.push_back(ch);
			} else {
				if (!tstr.empty())
					tstr.pop_back();
			}
		}
		if (sstr == tstr) {
			return true;
		} else {
			return false;
		}
	}
};
// @lc code=end

/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */

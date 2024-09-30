/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	string removeDuplicates(string s) {
		if (s.size() == 1)
			return s;
		int lens = s.size();
		int site = 0;
		int l = 0, r = 1;
		while (r < lens) {
			if (l == -1) {
				s[++l] = s[r++];
			} else if (r < lens && s[l] == s[r]) {
				l--;
				r++;
			} else {
				s[++l] = s[r++];
			}
		}
		s.resize(l + 1);
		return s;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

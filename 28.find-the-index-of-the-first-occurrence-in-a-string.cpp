/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int strStr(string haystack, string needle) {
		vector<int> next(needle.size(), 0);
		getNext(next, needle);
		int j = 0;
		for (int i = 0; i < haystack.size(); i++) {
			while (j > 0 && haystack[i] != needle[j]) {
				j = next[j - 1];
			}
			if (haystack[i] == needle[j]) {
				j++;
			}
			if (j == needle.size()) {
				return (i - needle.size() + 1);
			}
		}
		return -1;
	}

  private:
	void getNext(vector<int> &next, const string &s) {
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j]) {
				j = next[j - 1];
			}
			if (s[i] == s[j]) {
				j++;
			}
			next[i] = j;
		}
	}
};
// @lc code=end

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	string reverseWords(string s) {
		removespace(s);
		reverseWord(s);
		reverse(s, 0, s.size() - 1);
		return s;
	}

  private:
	void removespace(string &s) {
		int lens = s.size();
		int slow = 0;
		for (int i = 0; i < lens; i++) {
			if (s[i] != ' ') {
				if (slow != 0)
					s[slow++] = ' ';
				while (i < lens && s[i] != ' ') {
					s[slow++] = s[i++];
				}
			}
		}
		s.resize(slow);
	}
	void reverseWord(string &s) {
		int l = 0, r = 0;
		for (int i = 0; i < s.size(); i++) {
			l = i, r = i;
			while (r < s.size() && s[r] != ' ') {
				r++;
			}
			reverse(s, l, r - 1);
			i = r;
		}
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
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

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
		removeSpaces(s);
		int lens = s.size() - 1;
		if (lens <= 2)
			return s;
		reverse(s, 0, lens);
		int l, r = 0;
		int i = 0;
		int tmp = 0;
		while (i < lens) {
			while (s[tmp] != ' ' && tmp <= lens) {
				tmp++;
			}
			l = i;
			r = tmp - 1;
			i = tmp + 1;
			while (l < r) {
				char tmp = s[l];
				s[l] = s[r];
				s[r] = tmp;
				l++;
				r--;
			}
			tmp++;
		}
		return s;
	}

  private:
	void reverse(string &s, int l, int r) {
		while (l < r) {
			char tmp = s[r];
			s[r] = s[l];
			s[l] = tmp;
			l++;
			r--;
		}
	}

	void removeSpaces(string &s) {
		int slow = 0;
		int l = 0;
		int lens = s.size();
		while (s[l] == ' ') {
			l++;
		}
		while (l < lens) {
			while (l < lens && s[l] != ' ') {
				s[slow++] = s[l++];
			}
			while (l < lens && s[l] == ' ') {
				l++;
			}
			if (l >= lens)
				break;
			s[slow++] = ' ';
		}
		s.resize(slow);
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

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] 重复的子字符串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool repeatedSubstringPattern(string s) {
		int lens = s.size();
		std::vector<int> next(lens);
		getNext(s, next);
		if (next[lens - 1] > 0 && lens % (lens - next[lens - 1]) == 0) {
			return true;
		}
		return false;
	}

  private:
	void getNext(const std::string &s, std::vector<int> &next) {
		int j = 0;
		int lens = next.size();
		for (int i = 1; i < lens; i++) {
			while (j > 0 && s[j] != s[i]) {
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
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

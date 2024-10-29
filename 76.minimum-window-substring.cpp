/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	string minWindow(string s, string t) {
		int sArr[52] = {0}, tArr[52] = {0};
		int todo = 0;
		string result;
		for (const char &ch : t) {
			tArr[getPos(ch)]++;
			todo = tArr[getPos(ch)] == 1 ? todo + 1 : todo;
		}
		int l = 0, r = 0;
		for (const char &ch : s) {
			sArr[getPos(ch)]++;
			r++;
			if (sArr[getPos(ch)] == tArr[getPos(ch)] && tArr[getPos(ch)]) {
				todo--;
			}
			while (l < s.size() && sArr[getPos(s[l])] > tArr[getPos(s[l])]) {
				sArr[getPos(s[l])]--;
				l++;
			}
			if (!todo && (result.size() > r - l || result.size() == 0)) {
				result = s.substr(l, r - l);
			}
		}
		return result;
	}

  private:
	int getPos(char ch) {
		return ch >= 97 && ch <= 122 ? ch - 97 : ch - 39;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=30204
 *
 * [844] 比较含退格的字符串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool backspaceCompare(string s, string t) {
		int pslen = 0;
		int tslen = 0;
		string ps = process(s, pslen);
		string ts = process(t, tslen);
		if (pslen != tslen)
			return false;
		return compare(ps, ts, pslen);
	}

  private:
	string process(string str, int &len) {
		int lens = str.size();
		int fast = 0, slow = 0;
		while (fast < lens) {
			if (str[fast] == '#') {
				fast++;
				slow = slow - 1 > 0 ? slow - 1 : 0;
			} else
				str[slow++] = str[fast++];
		}
		len = slow;
		return str;
	}

	bool compare(string str1, string str2, int lens) {
		int i = 0;
		while (i < lens) {
			if (str1[i] != str2[i])
				return false;
			i++;
		}
		return true;
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

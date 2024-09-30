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
		int lens1 = needle.length();
		int lens2 = haystack.length();
		vector<int> vec(lens1);
		getNext(needle, vec);
		int cur1 = 0;
		int cur2 = 0;
		int start = 0;
		while (1) {
			if (cur1 == lens1) {
				return cur2 - cur1;
			} else if (cur2 == lens2) {
				break;
			}
			while (cur1 > 0 && needle[cur1] != haystack[cur2]) {
				cur1 = vec[cur1 - 1];
			}
			if (cur1 == 0)
				start = cur2;
			if (needle[cur1] == haystack[cur2]) {
				cur1++;
			}
			cur2++;
		}
		return -1;
	}

  private:
	void getNext(const string &str, vector<int> &next) {
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < str.size(); i++) {
			while (j > 0 && str[i] != str[j]) {
				j = next[j - 1];
			}
			if (str[i] == str[j]) {
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

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] 赎金信
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool canConstruct(string ransomNote, string magazine) {
		int m_arr[26] = {0};
		int r_arr[26] = {0};
		for (const char &ch : magazine) {
			m_arr[ch - 'a']++;
		}
		for (const char &ch : ransomNote) {
			r_arr[ch - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (r_arr[i] > m_arr[i]) {
				return false;
			}
		}
		return true;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */

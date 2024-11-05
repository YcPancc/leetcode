/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	string removeDuplicates(string s) {
		stack<char> st;
		for (const char &ch : s) {
			if (!st.empty() && ch == st.top()) {
				st.pop();
			} else {
				st.push(ch);
			}
		}
		string result;
		while (!st.empty()) {
			result += st.top();
			st.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

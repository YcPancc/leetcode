/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool isValid(string s) {
		stack<char> st;
		for (const char &ch : s) {
			if (ch == '{' || ch == '[' || ch == '(') {
				st.push(ch);
			} else if (ch == '}' || ch == ']' || ch == ')') {
				switch (ch) {
				case '}': {
					if (!st.empty() && st.top() == '{') {
						st.pop();
					} else {
						return false;
					}
					break;
				}
				case ']': {
					if (!st.empty() && st.top() == '[') {
						st.pop();
					} else {
						return false;
					}
					break;
				}
				case ')': {
					if (!st.empty() && st.top() == '(') {
						st.pop();
					} else {
						return false;
					}
					break;
				}
				}
			}
		}
		if (st.empty())
			return true;
		return false;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */

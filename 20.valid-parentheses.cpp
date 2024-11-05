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
			switch (ch) {
			case '(':
			case '[':
			case '{':
				st.push(ch);
				break;
			case ']': {
				if (st.empty() || st.top() != '[') {
					return false;
				}
				st.pop();
				break;
			}
			case '}': {
				if (st.empty() || st.top() != '{') {
					return false;
				}
				st.pop();
				break;
			}
			case ')': {
				if (st.empty() || st.top() != '(') {
					return false;
				}
				st.pop();
				break;
			}
			}
		}
		if (!st.empty()) {
			return false;
		}
		return true;
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

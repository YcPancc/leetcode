/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int evalRPN(vector<string> &tokens) {
		stack<long long> st;
		for (const string &token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				long long num1 = st.top();
				st.pop();
				long long num2 = st.top();
				st.pop();
				if (token == "+")
					st.push(num2 + num1);
				else if (token == "-")
					st.push(num2 - num1);
				else if (token == "*")
					st.push(num2 * num1);
				else
					st.push(num2 / num1);
			} else {
				st.push(stoll(token));
			}
		}
		return st.top();
	}
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

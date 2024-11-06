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
		stack<string> st;
		int result = 0;
		for (const string &str : tokens) {
			if (str == "+" || str == "-" || str == "*" || str == "/") {
				int second = stoi(st.top());
				st.pop();
				int first = stoi(st.top());
				st.pop();
				if (str == "+")
					st.push(to_string(first + second));
				else if (str == "-")
					st.push(to_string(first - second));
				else if (str == "*")
					st.push(to_string(first * second));
				else
					st.push(to_string(first / second));
			} else {
				st.push(str);
			}
		}
		return stoi(st.top());
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

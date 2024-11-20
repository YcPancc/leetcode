/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<string> result;
	void backtracking(const string &str, const string &nowStr, int start, int level) {
		if (level == 5) {
			if (start == str.size())
				result.push_back(nowStr);
			return;
		}
		for (int i = start; i < str.size() + level - 4; i++) {
			string str_num = str.substr(start, i - start + 1);
			if (stoi(str_num) > 255) {
				break;
			} else {
				if (level == 1) {
					backtracking(str, nowStr + str_num, i + 1, level + 1);
				} else {
					backtracking(str, nowStr + '.' + str_num, i + 1, level + 1);
				}
				if (stoi(str_num) == 0)
					break;
			}
		}
	}

  public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() < 4 || s.size() > 12)
			return {};
		backtracking(s, "", 0, 1);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

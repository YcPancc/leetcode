/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<char>> mapping = {
		{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'},
	};
	vector<string> result;
	string str = "";
	void process(const string &s, int site) {
		if (site == s.size()) {
			result.push_back(str);
			return;
		}
		int pos = s[site] - '2';
		for (char ch : mapping[pos]) {
			str.push_back(ch);
			process(s, site + 1);
			str.pop_back();
		}
	}

  public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		process(digits, 0);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

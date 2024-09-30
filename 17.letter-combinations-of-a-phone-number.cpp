/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
 */

// @lcpr-template-start
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	std::vector<std::vector<char>> vec = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
	std::vector<std::string> result;
	std::string path = "";
	void backtracking(const int &lens, const int &cur, const std::string &str) {
		if (path.size() == lens) {
			result.push_back(path);
			return;
		}
		for (char ch : vec[str[cur] - '2']) {
			path.push_back(ch);
			backtracking(lens, cur + 1, str);
			path.pop_back();
		}
		return;
	}

  public:
	std::vector<std::string> letterCombinations(std::string digits) {
		int lens = digits.size();
		if (!lens)
			return result;
		backtracking(lens, 0, digits);
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

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<vector<string>> result;
	vector<string> path;
	bool isPalindrome(string str, int l, int r) {
		while (l < r) {
			if (str[l] != str[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
	void backtracking(string str, int start) {
		if (start >= str.size()) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < str.size(); i++) {
			if (isPalindrome(str, start, i)) {
				string tmp = str.substr(start, i - start + 1);
				path.push_back(tmp);
			} else {
				continue;
			}
			backtracking(str, i + 1);
			path.pop_back();
		}
	}

  public:
	vector<vector<string>> partition(string s) {
		backtracking(s, 0);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

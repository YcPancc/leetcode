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
	bool isVaild(const string &s, int l, int r) {
		while (l < r) {
			if (s[l] != s[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
	vector<vector<string>> result;
	vector<string> arr;
	void backtracking(const string &str, const int &start) {
		if (start == str.size()) {
			result.push_back(arr);
		}
		for (int i = start; i < str.size(); i++) {
			if (isVaild(str, start, i)) {
				arr.push_back(str.substr(start, i - start + 1));
				backtracking(str, i + 1);
				arr.pop_back();
			}
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

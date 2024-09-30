/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	vector<string> result;
	bool isValid(const string &str, const int &start, const int &end) {
		if (start > end)
			return false;
		if (str[start] == '0' && start != end)
			return false;
		int nums = 0;
		for (int i = start; i <= end; i++) {
			if (str[i] > '9' || str[i] < '0')
				return false;
			nums = nums * 10 + (str[i] - '0');
			if (nums > 255)
				return false;
		}
		return true;
	}

	void backtracking(string &str, int startIndex, int pointNums) {
		if (pointNums == 3) {
			if (isValid(str, startIndex, str.size() - 1)) {
				result.push_back(str);
			}
			return;
		}
		for (int i = startIndex; i < str.size(); i++) {
			if (isValid(str, startIndex, i)) {
				str.insert(str.begin() + i + 1, '.');
				pointNums++;
				backtracking(str, i + 2, pointNums);
				pointNums--;
				str.erase(str.begin() + i + 1);
			} else {
				break;
			}
		}
	}

  public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() < 4 && s.size() > 12)
			return {};
		backtracking(s, 0, 0);
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

#include <bits/stdc++.h>
using namespace std;

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
			cout << level << " " << str_num << '\n';
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
		backtracking(s, "", 0, 1);
		return result;
	}
};

int main() {
	Solution s;
	s.restoreIpAddresses("25525511135");
}
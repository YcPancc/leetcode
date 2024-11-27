/*
 * @lc app=leetcode.cn id=860 lang=cpp
 * @lcpr version=30204
 *
 * [860] 柠檬水找零
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool lemonadeChange(vector<int> &bills) {
		int five_nums = 0, ten_nums = 0;
		for (const int &bill : bills) {
			if (bill == 5) {
				five_nums++;
			} else if (bill == 10) {
				if (five_nums == 0) {
					return false;
				} else {
					five_nums--;
					ten_nums++;
				}
			} else {
				if (ten_nums == 0) {
					if (five_nums < 3) {
						return false;
					} else {
						five_nums -= 3;
					}
				} else {
					if (five_nums == 0) {
						return false;
					} else {
						five_nums--;
						ten_nums--;
					}
				}
			}
		}
		return true;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [5,5,5,10,20]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,10,10,20]\n
// @lcpr case=end

 */

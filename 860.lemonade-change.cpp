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
		int five = 0, ten = 0, twenty = 0;
		for (int bill : bills) {
			if (bill == 5)
				five++;
			else if (bill == 10) {
				if (five > 0) {
					ten++;
					five--;
				} else
					return false;
			} else if (bill == 20) {
				if (ten > 0) {
					if (five > 0) {
						five--;
						ten--;
						twenty++;
					} else {
						return false;
					}
				} else {
					if (five >= 3) {
						five -= 3;
					} else {
						return false;
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

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30204
 *
 * [134] 加油站
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int start = 0;
		int curSum = 0;
		int totalSum = 0;
		for (int i = 0; i < gas.size(); i++) {
			curSum += gas[i] - cost[i];
			totalSum += gas[i] - cost[i];
			if (curSum < 0) {
				start = i + 1;
				curSum = 0;
			}
		}
		if (totalSum < 0)
			return -1;
		return start;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */

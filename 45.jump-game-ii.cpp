/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int jump(vector<int> &nums) {
		if (nums.size() == 1)
			return 0;
		int curDistence = 0;
		int nextDistence = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			nextDistence = max(int(nums[i] + i), nextDistence);
			if (i == curDistence) {
				ans++;
				curDistence = nextDistence;
				if (nextDistence >= nums.size() - 1)
					break;
			}
		}
		return ans;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

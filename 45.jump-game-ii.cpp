/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int jump(vector<int> &nums) {
		if (nums.size() == 1)
			return 0;
		int curCover = 0;
		int nextCover = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			nextCover = max(nextCover, i + nums[i]);
			if (i == curCover) {
				ans++;
				curCover = nextCover;
				if (curCover >= nums.size() - 1)
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

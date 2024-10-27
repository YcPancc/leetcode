/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] 移动零
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	void moveZeroes(vector<int> &nums) {
		int fast = 0, slow = 0;
		int lens = nums.size();
		while (fast < lens) {
			if (nums[fast] == 0) {
				fast++;
			} else {
				nums[slow++] = nums[fast++];
			}
		}
		while (slow < lens) {
			nums[slow++] = 0;
		}
	}
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

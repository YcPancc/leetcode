/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30204
 *
 * [26] 删除有序数组中的重复项
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int removeDuplicates(vector<int> &nums) {
		int pre = nums[0];
		int fast = 1, slow = 1;
		int lens = nums.size();
		while (fast < lens) {
			if (nums[fast] == pre) {
				fast++;
			} else {
				pre = nums[fast];
				nums[slow++] = nums[fast++];
			}
		}
		return slow;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

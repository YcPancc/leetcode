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
		if (nums.size() <= 1)
			return nums.size();
		int lens = nums.size();
		int fast = 0, slow = 0;
		while (fast < lens) {
			nums[slow++] = nums[fast++];
			while (fast < lens && nums[fast] == nums[fast - 1]) {
				fast++;
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

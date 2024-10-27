/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30204
 *
 * [27] 移除元素
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int removeElement(vector<int> &nums, int val) {
		int fast = 0, slow = 0;
		int lens = nums.size();
		while (fast < lens) {
			if (nums[fast] == val) {
				fast++;
			} else {
				nums[slow++] = nums[fast++];
			}
		}
		return slow;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */

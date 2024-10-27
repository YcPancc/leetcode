/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30204
 *
 * [35] 搜索插入位置
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int searchInsert(vector<int> &nums, int target) {
		int lens = nums.size() - 1;
		int l = 0, r = lens;
		int mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int lens = nums.size() - 1;
		int l = 0, r = lens;
		int mid;
		int left = -2, right = -2;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] > target) {
				r = mid - 1;
			} else if (nums[mid] == target) {
				left = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (left == -2) {
			return {-1, -1};
		}
		l = 0, r = lens;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] > target) {
				r = mid - 1;
			} else if (nums[mid] == target) {
				right = mid;
				l = mid + 1;
			} else {
				l = mid + 1;
			}
		}
		return {left, right};
	}
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

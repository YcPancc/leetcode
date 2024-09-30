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
		int r = lens;
		int l = 0;
		int lres = -1, rres = -1;
		int mid = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] > target) {
				r = mid - 1;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				lres = mid;
				r = r - 1;
			}
		}
		if (lres == -1)
			return {-1, -1};
		r = lens;
		l = 0;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] > target) {
				r = mid - 1;
			} else if (nums[mid] < target) {
				l = mid + 1;
			} else {
				rres = mid;
				l = l + 1;
			}
		}
		return {lres, rres};
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

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> sortedSquares(vector<int> &nums) {
		int lens = nums.size();
		int l = 0, r = lens - 1;
		vector<int> result = vector<int>(lens, 0);
		for (int i = lens - 1; i >= 0; i--) {
			if (nums[l] * nums[l] > nums[r] * nums[r]) {
				result[i] = nums[l] * nums[l];
				l++;
			} else {
				result[i] = nums[r] * nums[r];
				r--;
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> sortedSquares(vector<int> &nums) {
		int r = nums.size() - 1;
		vector<int> res(r + 1);
		int j = r;
		int l = 0;
		while (l <= r) {
			if (abs(nums[l]) >= abs(nums[r])) {
				res[j--] = nums[l] * nums[l];
				l++;
			} else {
				res[j--] = nums[r] * nums[r];
				r--;
			}
		}
		return res;
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

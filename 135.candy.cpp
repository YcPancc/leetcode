/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30204
 *
 * [135] 分发糖果
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int candy(vector<int> &ratings) {
		vector<int> nums(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				nums[i] = nums[i - 1] + 1;
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				nums[i] = max(nums[i], nums[i + 1] + 1);
		}
		int sum = 0;
		for (const int &num : nums) {
			sum += num;
		}
		return sum;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

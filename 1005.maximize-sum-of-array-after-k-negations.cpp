/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 * @lcpr version=30204
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
	static bool cmp(int a, int b) {
		return abs(a) > abs(b);
	}

  public:
	int largestSumAfterKNegations(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0 && k > 0) {
				nums[i] = nums[i] * -1;
				k--;
			}
		}
		if (k % 2 == 1)
			nums[nums.size() - 1] *= -1;
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
// [4,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1,0,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,-3,-1,5,-4]\n2\n
// @lcpr case=end

 */

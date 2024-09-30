/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		unordered_set<int> nums1_set(nums1.begin(), nums1.end());
		unordered_set<int> common_set;
		for (const int &i : nums2) {
			if (nums1_set.find(i) != nums1_set.end()) {
				common_set.insert(i);
			}
		}
		return vector(common_set.begin(), common_set.end());
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */

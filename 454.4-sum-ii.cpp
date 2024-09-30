/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	// unorderd_map 的时间损耗远大于数组, 相同时间复杂度下能用数组就用数组
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
		unordered_map<int, int> part1_map;
		for (const int &numi : nums1) {
			for (const int &numj : nums2) {
				part1_map[numi + numj]++;
			}
		}
		int sum = 0;
		for (const int &numi : nums3) {
			for (const int &numj : nums4) {
				const auto it = part1_map.find(-(numi + numj));
				if (it != part1_map.end())
					sum += it->second;
			}
		}
		return sum;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */

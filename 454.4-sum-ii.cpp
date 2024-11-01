/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
		unordered_map<int, int> map1;
		unordered_map<int, int> map2;
		for (const int &i : nums1) {
			for (const int &j : nums2) {
				map1[i + j]++;
			}
		}
		for (const int &i : nums3) {
			for (const int &j : nums4) {
				map2[i + j]++;
			}
		}
		int result = 0;
		for (const auto &p : map1) {
			const auto &it = map2.find(0 - p.first);
			if (it != map2.end()) {
				result += p.second * it->second;
			}
		}
		return result;
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

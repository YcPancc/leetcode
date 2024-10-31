/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30204
 *
 * [349] 两个数组的交集
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		unordered_set<int> set1(nums1.begin(), nums1.end());
		unordered_set<int> set2(nums2.begin(), nums2.end());
		vector<int> result;
		for (const int &num : set1) {
			if (set2.find(num) != set2.end()) {
				result.push_back(num);
			}
		}
		return result;
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

/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30204
 *
 * [904] 水果成篮
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int totalFruit(vector<int> &fruits) {
		int lens = fruits.size();
		unordered_map<int, int> buckets;
		int l = 0;
		int len = 0;
		for (int r = 0; r < lens; r++) {
			buckets[fruits[r]]++;
			while (buckets.size() > 2) {
				auto it = buckets.find(fruits[l]);
				it->second--;
				if (it->second == 0) {
					buckets.erase(it);
				}
				l++;
			}
			len = max(len, r - l + 1);
		}
		return len;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */

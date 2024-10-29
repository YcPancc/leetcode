/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30204
 *
 * [904] 水果成篮
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int totalFruit(vector<int> &fruits) {
		unordered_map<int, int> buckets;
		int lens = fruits.size();
		int result = 0;
		int l = 0, r = 0;
		for (; r < lens; r++) {
			buckets[fruits[r]]++;
			while (buckets.size() >= 3) {
				auto it = buckets.find(fruits[l]);
				l++;
				it->second--;
				if (it->second == 0)
					buckets.erase(it);
			}
			result = result < r - l + 1 ? r - l + 1 : result;
		}
		return result;
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

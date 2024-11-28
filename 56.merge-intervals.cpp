/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
	static bool cmp(const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	}

  public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> result;
		sort(intervals.begin(), intervals.end(), cmp);
		vector<int> vec = intervals[0];
		for (const vector<int> &interval : intervals) {
			if (interval[0] <= vec[1]) {
				vec[1] = vec[1] >= interval[1] ? vec[1] : interval[1];
			} else {
				result.push_back(vec);
				vec = interval;
			}
		}
		result.push_back(vec);
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

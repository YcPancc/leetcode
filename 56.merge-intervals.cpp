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
	static bool compare(const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	}

  public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		if (intervals.size() == 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), compare);
		vector<vector<int>> result;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] <= intervals[i - 1][1]) {
				intervals[i][0] = intervals[i - 1][0];
				intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
			} else {
				result.push_back(intervals[i - 1]);
			}
		}
		result.push_back(intervals[intervals.size() - 1]);
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

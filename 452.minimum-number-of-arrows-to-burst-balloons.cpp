/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30204
 *
 * [452] 用最少数量的箭引爆气球
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
	int findMinArrowShots(vector<vector<int>> &points) {
		sort(points.begin(), points.end(), cmp);
		int start = points[0][0], end = points[0][1];
		int nums = 1;
		for (const vector<int> &point : points) {
			if (point[0] <= end) {
				start = point[0];
				if (point[1] < end) {
					end = point[1];
				}
			} else {
				nums++;
				start = point[0];
				end = point[1];
			}
		}
		return nums;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */

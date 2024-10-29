/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int x1 = 0, x2 = n - 1, y1 = 0, y2 = n - 1;
		int nums = n >> 1;
		int num = 1;
		while (nums--) {
			for (int i = x1; i < x2; i++) {
				result[y1][i] = num++;
			}
			for (int j = y1; j < y2; j++) {
				result[j][x2] = num++;
			}
			for (int i = x2; i > x1; i--) {
				result[y2][i] = num++;
			}
			for (int j = y2; j > y1; j--) {
				result[j][x1] = num++;
			}
			x1++;
			y1++;
			x2--;
			y2--;
		}
		if (n % 2) {
			result[n >> 1][n >> 1] = num;
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

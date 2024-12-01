/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		int row_len = obstacleGrid.size();	  // 行数
		int col_len = obstacleGrid[0].size(); // 列数
		vector<vector<int>> dp(row_len, vector<int>(col_len, 0));
		for (int i = 0; i < row_len; i++) {
			if (obstacleGrid[i][0] == 1)
				break;
			dp[i][0] = 1;
		}
		for (int i = 0; i < col_len; i++) {
			if (obstacleGrid[0][i] == 1)
				break;
			dp[0][i] = 1;
		}
		for (int i = 1; i < row_len; i++) {
			for (int j = 1; j < col_len; j++) {
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[row_len - 1][col_len - 1];
	}
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */

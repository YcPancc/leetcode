/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] 螺旋矩阵 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int l = 0, r = n - 1, t = 0, b = n - 1;
		int num = 1, end = n * n;
		while (num <= end) {
			for (int i = l; i <= r; i++)
				result[t][i] = num++;
			t++;
			for (int i = t; i <= b; i++) {
				result[i][r] = num++;
			}
			r--;
			for (int i = r; i >= l; i--) {
				result[b][i] = num++;
			}
			b--;
			for (int i = b; i >= t; i--) {
				result[i][l] = num++;
			}
			l++;
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

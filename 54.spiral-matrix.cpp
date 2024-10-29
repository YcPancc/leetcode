/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		int x_lens = matrix[0].size();
		int y_lens = matrix.size();
		vector<int> result(x_lens * y_lens);
		int x1 = 0, x2 = x_lens - 1, y1 = 0, y2 = y_lens - 1;
		int x_y;
		int min;
		if (x_lens > y_lens) {
			x_y = 1;
			min = y_lens;
		} else {
			x_y = 0;
			min = x_lens;
		}
		int isSingle = min % 2;
		int pos = 0;
		if (isSingle) {
			int times = min >> 1;
			while (times--) {
				for (int i = x1; i < x2; i++) {
					result[pos++] = matrix[y1][i];
				}
				for (int j = y1; j < y2; j++) {
					result[pos++] = matrix[j][x2];
				}
				for (int i = x2; i > x1; i--) {
					result[pos++] = matrix[y2][i];
				}
				for (int j = y2; j > y1; j--) {
					result[pos++] = matrix[j][x1];
				}
				x1++;
				x2--;
				y1++;
				y2--;
			}
			if (x_y == 0) {
				for (int j = y1; j <= y2; j++) {
					result[pos++] = matrix[j][x1];
				}
			} else {
				for (int i = x1; i <= x2; i++) {
					result[pos++] = matrix[y1][i];
				}
			}
		} else {
			int times = min >> 1;
			while (times--) {
				for (int i = x1; i < x2; i++) {
					result[pos++] = matrix[y1][i];
				}
				for (int j = y1; j < y2; j++) {
					result[pos++] = matrix[j][x2];
				}
				for (int i = x2; i > x1; i--) {
					result[pos++] = matrix[y2][i];
				}
				for (int j = y2; j > y1; j--) {
					result[pos++] = matrix[j][x1];
				}
				x1++;
				x2--;
				y1++;
				y2--;
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

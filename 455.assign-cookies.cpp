/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30204
 *
 * [455] 分发饼干
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int findContentChildren(vector<int> &g, vector<int> &s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int g_len = g.size() - 1;
		int s_len = s.size() - 1;
		int nums = 0;
		while (g_len != -1 && s_len != -1) {
			if (s[s_len] >= g[g_len]) {
				nums++;
				s_len--;
			}
			g_len--;
		}
		return nums;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

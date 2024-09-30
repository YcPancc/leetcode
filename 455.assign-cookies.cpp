/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30204
 *
 * [455] 分发饼干
 */

// @lcpr-template-start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	int findContentChildren(vector<int> &g, vector<int> &s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int g_lens = g.size() - 1;
		int s_lens = s.size() - 1;
		int sum = 0;
		for (int i = g_lens; i >= 0; i--) {
			if (s_lens > -1 && s[s_lens] >= g[i]) {
				sum++;
				s_lens--;
			}
		}
		return sum;
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

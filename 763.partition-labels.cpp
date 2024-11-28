/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30204
 *
 * [763] 划分字母区间
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	vector<int> partitionLabels(string s) {
		int dis[26] = {0};
		for (int i = 0; i < s.size(); i++) {
			dis[s[i] - 'a'] = i;
		}
		int cur = 0;
		int start = 0;
		vector<int> result;
		while (cur < s.size()) {
			int max_dis = dis[s[cur] - 'a'];
			for (; cur <= max_dis; cur++) {
				max_dis = max_dis >= dis[s[cur] - 'a'] ? max_dis : dis[s[cur] - 'a'];
			}
			result.push_back(cur - start);
			start = cur;
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */

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
		vector<int> arr(26, 0);
		for (int i = 0; i < s.size(); i++) {
			arr[s[i] - 'a'] = i;
		}
		int site;
		vector<int> result;
		int start;
		int i;
		for (i = 0; i < s.size();) {
			start = i;
			site = arr[s[i] - 'a'];
			while (i <= site) {
				if (arr[s[i] - 'a'] > site) {
					site = arr[s[i] - 'a'];
				}
				i++;
			}
			result.push_back(i - start);
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

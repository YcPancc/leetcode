/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] 有效的字母异位词
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool isAnagram(string s, string t) {
		vector<int> nums(26, 0);
		for (char letter : s) {
			nums[letter - 'a']++;
		}
		for (char letter : t) {
			nums[letter - 'a']--;
		}
		for (int i : nums) {
			if (i)
				return false;
		}
		return true;
	}
};
// @lc code=end

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

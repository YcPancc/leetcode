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
		int arr[26] = {0};
		for (char &ch : s) {
			arr[ch - 'a']++;
		}
		for (char &ch : t) {
			arr[ch - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i]) {
				return false;
			}
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

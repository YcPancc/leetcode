/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐数
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
	bool isHappy(int n) {
		unordered_set<int> process_set;
		int result;
		while (n != 1) {
			if (process_set.find(n) != process_set.end())
				return false;
			process_set.insert(n);
			n = process(n);
		}
		return true;
	}

	int process(int num) {
		int sum = 0;

		while (num) {
			sum += (num % 10) * (num % 10);
			num /= 10;
		}

		return sum;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

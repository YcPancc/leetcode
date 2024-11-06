/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	class MyQueue {
	  public:
		deque<int> dq;
		MyQueue() {
		}
		void pop(int val) {
			if (!dq.empty() && val == dq.front())
				dq.pop_front();
		}
		int front() {
			return dq.front();
		}
		void push(int val) {
			while (!dq.empty() && dq.back() < val) {
				dq.pop_back();
			}
			dq.push_back(val);
		}
	};

  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		MyQueue mq;
		int l = 0, r = 0;
		int lens = nums.size();
		while (r < k) {
			mq.push(nums[r]);
			r++;
		}
		vector<int> result(lens - k + 1);
		result[l] = mq.front();
		while (r < lens) {
			mq.push(nums[r]);
			mq.pop(nums[l]);
			result[++l] = mq.front();
			r++;
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

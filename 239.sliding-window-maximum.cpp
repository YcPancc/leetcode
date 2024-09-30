/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
 */

// @lcpr-template-start
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  private:
	class myQueue {
	  private:
		deque<int> deque;

	  public:
		myQueue() {
		}
		void pop(int value) {
			if (!deque.empty() && value == deque.front()) {
				deque.pop_front();
			}
		}

		void push(int value) {
			while (!deque.empty() && deque.back() < value) {
				deque.pop_back();
			}
			deque.push_back(value);
		}

		int front() {
			return deque.front();
		}
	};

  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		int lens = nums.size();
		int l = 0, r = k;
		myQueue myqueue;
		for (int i = 0; i < k; i++) {
			myqueue.push(nums[i]);
		}
		vector<int> result(lens + 1 - k);
		result[0] = myqueue.front();
		while (r < lens) {
			myqueue.pop(nums[l]);
			myqueue.push(nums[r]);
			l++;
			r++;
			result[l] = myqueue.front();
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

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30204
 *
 * [232] 用栈实现队列
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyQueue {
  private:
	stack<int> stIn;
	stack<int> stOut;

  public:
	MyQueue() {
	}

	void push(int x) {
		stIn.push(x);
	}

	int pop() {
		if (stOut.empty()) {
			while (!stIn.empty()) {
				int val = stIn.top();
				stOut.push(val);
				stIn.pop();
			}
		}
		int val = stOut.top();
		stOut.pop();
		return val;
	}

	int peek() {
		if (stOut.empty()) {
			while (!stIn.empty()) {
				int val = stIn.top();
				stOut.push(val);
				stIn.pop();
			}
		}
		int val = stOut.top();
		return val;
	}

	bool empty() {
		return stIn.empty() && stOut.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

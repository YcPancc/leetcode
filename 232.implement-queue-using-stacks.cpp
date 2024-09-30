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
	stack<int> stdIn;
	stack<int> stdOut;

  public:
	MyQueue() {
	}

	void push(int x) {
		stdIn.push(x);
	}

	int pop() {
		if (stdOut.empty()) {
			while (!stdIn.empty()) {
				int tmp = stdIn.top();
				stdIn.pop();
				stdOut.push(tmp);
			}
		}
		int tmp = stdOut.top();
		stdOut.pop();
		return tmp;
	}

	int peek() {
		if (stdOut.empty()) {
			while (!stdIn.empty()) {
				int tmp = stdIn.top();
				stdIn.pop();
				stdOut.push(tmp);
			}
		}
		int tmp = stdOut.top();
		return tmp;
	}

	bool empty() {
		if (stdIn.empty() && stdOut.empty()) {
			return true;
		}
		return false;
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

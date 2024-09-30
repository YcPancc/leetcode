/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyStack {
  private:
	queue<int> stdIn;
	queue<int> stdOut;

  public:
	MyStack() {
	}

	void push(int x) {
		stdIn.push(x);
	}

	int pop() {
		while (stdIn.size() > 1) {
			stdOut.push(stdIn.front());
			stdIn.pop();
		}
		int tmp = stdIn.front();
		stdIn.pop();
		while (!stdOut.empty()) {
			stdIn.push(stdOut.front());
			stdOut.pop();
		}
		return tmp;
	}

	int top() {
		while (stdIn.size() > 1) {
			stdOut.push(stdIn.front());
			stdIn.pop();
		}
		int tmp = stdIn.front();
		stdIn.pop();
		while (!stdOut.empty()) {
			stdIn.push(stdOut.front());
			stdOut.pop();
		}
		stdIn.push(tmp);
		return tmp;
	}

	bool empty() {
		if (stdIn.empty())
			return true;
		return false;
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

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
	queue<int> quIn;
	queue<int> quOut;

  public:
	MyStack() {
	}

	void push(int x) {
		quIn.push(x);
	}

	int pop() {
		while (quIn.size() > 1) {
			int val = quIn.front();
			quIn.pop();
			quOut.push(val);
		}
		int val = quIn.front();
		quIn.pop();
		while (!quOut.empty()) {
			int val = quOut.front();
			quOut.pop();
			quIn.push(val);
		}
		return val;
	}

	int top() {
		return quIn.back();
	}

	bool empty() {
		return quIn.empty();
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

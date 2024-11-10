/*
 * @lc app=leetcode.cn id=429 lang=cpp
 * @lcpr version=30204
 *
 * [429] N 叉树的层序遍历
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
	int val;
	vector<Node *> children;
	Node() {
	}
	Node(int _val) {
		val = _val;
	}
	Node(int _val, vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
  public:
	vector<vector<int>> levelOrder(Node *root) {
		if (!root)
			return {};
		queue<Node *> qu;
		qu.push(root);
		vector<vector<int>> result;
		while (!qu.empty()) {
			int lens = qu.size();
			vector<int> arr(lens);
			for (int i = 0; i < lens; i++) {
				Node *cur = qu.front();
				qu.pop();
				arr[i] = cur->val;
				for (const auto &p : cur->children) {
					qu.push(p);
				}
			}
			result.push_back(arr);
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

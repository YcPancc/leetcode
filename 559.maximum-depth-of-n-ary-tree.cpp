/*
 * @lc app=leetcode.cn id=559 lang=cpp
 * @lcpr version=30204
 *
 * [559] N 叉树的最大深度
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
  private:
	int getdepth(Node *cur) {
		if (!cur)
			return 0;
		int lens = 0;
		for (Node *node : cur->children) {
			int len = getdepth(node);
			lens = lens > len ? lens : len;
		}
		return lens + 1;
	}

  public:
	int maxDepth(Node *root) {
		return getdepth(root);
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

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 * @lcpr version=30204
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {
	}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
	}

	Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {
	}
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
	Node *connect(Node *root) {
		if (!root)
			return nullptr;
		queue<Node *> qu;
		qu.push(root);
		while (!qu.empty()) {
			int lens = qu.size();
			Node *pre, *cur;
			for (int i = 0; i < lens; i++) {
				if (i == 0) {
					pre = qu.front();
					qu.pop();
					cur = pre;
				} else {
					cur = qu.front();
					qu.pop();
					pre->next = cur;
					pre = cur;
				}
				if (cur->left)
					qu.push(cur->left);
				if (cur->right)
					qu.push(cur->right);
			}
		}
		return root;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,null,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30204
 *
 * [206] 反转链表
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {
	}
	ListNode(int x) : val(x), next(nullptr) {
	}
	ListNode(int x, ListNode *next) : val(x), next(next) {
	}
};

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
	ListNode *reverseList(ListNode *head) {
		ListNode *cur = head;
		ListNode *pre = nullptr;
		while (cur != nullptr) {
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

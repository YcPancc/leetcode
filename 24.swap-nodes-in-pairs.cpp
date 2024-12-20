/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
	ListNode *swapPairs(ListNode *head) {
		ListNode *Head = new ListNode(0, head);
		ListNode *cur = Head;
		while (cur->next && cur->next->next) {
			ListNode *tmp = cur->next->next->next;
			cur->next->next->next = cur->next;
			cur->next = cur->next->next;
			cur->next->next->next = tmp;
			cur = cur->next->next;
		}
		head = Head->next;
		delete Head;
		return head;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

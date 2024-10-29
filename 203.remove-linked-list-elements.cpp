/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
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
	ListNode *removeElements(ListNode *head, int val) {
		ListNode *Head = new ListNode(0, head);
		ListNode *cur = Head;
		while (cur->next != nullptr) {
			if (cur->next->val == val) {
				ListNode *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			} else {
				cur = cur->next;
			}
		}
		head = Head->next;
		delete Head;
		return head;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

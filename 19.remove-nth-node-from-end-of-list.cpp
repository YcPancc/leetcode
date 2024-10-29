/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *Head = new ListNode(0, head);
		ListNode *fast = Head;
		ListNode *slow = Head;
		while (n--) {
			fast = fast->next;
		}
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		ListNode *tmp = slow->next;
		slow->next = slow->next->next;
		delete tmp;
		head = Head->next;
		delete Head;
		return head;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

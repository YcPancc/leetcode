/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int A_lens = 0;
		int B_lens = 0;
		ListNode *cur = headA;
		while (cur != nullptr) {
			A_lens++;
			cur = cur->next;
		}
		cur = headB;
		while (cur != nullptr) {
			B_lens++;
			cur = cur->next;
		}
		int sub = A_lens - B_lens;
		if (sub > 0) {
			while (sub--) {
				headA = headA->next;
			}
		} else if (sub < 0) {
			sub = -sub;
			while (sub--) {
				headB = headB->next;
			}
		}
		ListNode *result = nullptr;
		while (headA != nullptr) {
			if (headA == headB) {
				result = headA;
				break;
			} else {
				headA = headA->next;
				headB = headB->next;
			}
		}
		return result;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

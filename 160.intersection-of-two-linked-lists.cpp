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
		ListNode *curA = headA;
		ListNode *curB = headB;
		int lensA = 0, lensB = 0;
		while (curA) {
			lensA++;
			curA = curA->next;
		}
		while (curB) {
			lensB++;
			curB = curB->next;
		}
		curA = headA;
		curB = headB;
		if (lensA > lensB) {
			int time = lensA - lensB;
			while (time--) {
				curA = curA->next;
			}
		} else if (lensA < lensB) {
			int time = lensB - lensA;
			while (time--) {
				curB = curB->next;
			}
		}
		while (curA && curB) {
			if (curA == curB)
				return curA;
			curA = curA->next;
			curB = curB->next;
		}
		return nullptr;
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

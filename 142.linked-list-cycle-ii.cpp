/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] 环形链表 II
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
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
			if (slow == fast) {
				ListNode *index1 = fast;
				ListNode *index2 = head;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // 返回环的入口
			}
		}
		return NULL;
	}
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

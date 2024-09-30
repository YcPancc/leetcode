/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class MyLinkedList {
  private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int val) : val(val), next(nullptr) {
		}
	};
	ListNode *Head;
	int lens;

  public:
	MyLinkedList() {
		Head = new ListNode(0);
		lens = 0;
	}

	int get(int index) {
		if (index > lens - 1 || index < 0)
			return -1;
		ListNode *cur = Head->next;
		while (index--) {
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		ListNode *tmp = new ListNode(val);
		tmp->next = Head->next;
		Head->next = tmp;
		lens++;
	}

	void addAtTail(int val) {
		ListNode *cur = Head;
		int nums = 0;
		while (nums < lens) {
			cur = cur->next;
			nums++;
		}
		ListNode *tmp = new ListNode(val);
		cur->next = tmp;
		lens++;
	}

	void addAtIndex(int index, int val) {
		if (!(index > lens || index < 0)) {
			ListNode *tmp = new ListNode(val);
			ListNode *cur = Head;
			while (index--) {
				cur = cur->next;
			}
			tmp->next = cur->next;
			cur->next = tmp;
			lens++;
		}
	}

	void deleteAtIndex(int index) {
		if (index >= lens)
			return;
		ListNode *cur = Head;
		while (index--) {
			cur = cur->next;
		}
		ListNode *tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		lens--;
	}
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

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
	struct Node {
		int value;
		Node *next;
		Node() : value(0), next(nullptr) {
		}
		Node(Node *next) : value(0), next(next) {
		}
		Node(int value) : value(value), next() {
		}
		Node(int value, Node *next) : value(value), next(next) {
		}
	};
	Node *Head;
	int length;

  public:
	MyLinkedList() {
		Head = new Node();
		length = 0;
	}

	int get(int index) {
		if (index >= length || index < 0)
			return -1;
		Node *cur = Head;
		while (index--) {
			cur = cur->next;
		}
		return cur->next->value;
	}

	void addAtHead(int val) {
		Head->next = new Node(val, Head->next);
		length++;
	}

	void addAtTail(int val) {
		addAtIndex(length, val);
	}

	void addAtIndex(int index, int val) {
		if (index > length || index < 0)
			return;
		Node *cur = Head;
		while (index--) {
			cur = cur->next;
		}
		cur->next = new Node(val, cur->next);
		length++;
	}

	void deleteAtIndex(int index) {
		if (index >= length || index < 0)
			return;
		Node *cur = Head;
		while (index--) {
			cur = cur->next;
		}
		Node *tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		length--;
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

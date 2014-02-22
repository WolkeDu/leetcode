#include <iostream>
// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* newhead = new ListNode(-1);
		ListNode* left = newhead;
		left->next = head;
		while(left->next != NULL && left->next->val < x) left = left->next;
		if(left->next == NULL){
			newhead = newhead->next;
			return  newhead;
		}
		ListNode* cur = left->next;
		while(cur->next != NULL){
			if(cur->next ->val < x){
				ListNode* tmp = cur->next;
				cur->next = tmp->next; //delete tmp

				tmp->next = left->next;// add tmp to left part
				left->next = tmp;
				left = tmp;
			}
			else cur = cur->next;
		}

		newhead = newhead->next;
		return newhead;
    }
};
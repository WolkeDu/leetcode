//* Definition for singly-linked list.
#pragma once
#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  }; 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL || head->next == NULL) return NULL;
		ListNode* pre = head;
		ListNode* cur = head;
		n++;
		while( n-- && cur!= NULL) cur = cur->next;
		if(n>0){ head = head->next; return head;}
		while(cur != NULL){
			cur = cur->next;
			pre = pre->next;
		}
		cur = pre->next->next;
		pre->next = cur;
		return head;
    }
};
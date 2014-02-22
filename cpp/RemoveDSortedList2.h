#include <iostream>
// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* newhead = new ListNode(0);
        ListNode* pre = newhead; // an auxiliary node
        pre->next = head;
        bool flag = false;
        while(cur->next != NULL){
            flag = false;
            while(cur->next != NULL && cur->val == cur->next->val){
                cur = cur->next; flag = true;
            }
            
            if(flag) {
                if(cur->next != NULL){
                    cur = cur->next;
                    pre->next = cur;
                }
                else pre->next = NULL;
				flag = false;
            }
            else if(cur->next != NULL) {
                pre = cur; cur = cur->next;
            }
        }
		newhead = newhead->next; // remove the auxiliary node
		return newhead;
    }
};
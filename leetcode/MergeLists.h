//**
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 //*/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ListNode* head;
		if(l1 == 0) return head = l2;
		if(l2 == 0) return head = l1;
		if(l1->val <= l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		ListNode* cur = head;
		while(1){
			if(l1 == 0 || l2 == 0) break;

			if(l1->val<= l2->val){
				cur->next = l1;
				//while(l1->val <= l2->val)
					l1 = l1->next;
				cur = cur->next;

			}
			else {
				cur->next = l2;
			//	while(l1->val > l2->val)
					l2 = l2->next;	
				cur = cur->next;			
			}
		}
		if(l1 != 0) 
			cur->next = l1;
		else if(l2 != 0)
			cur->next = l2;

		return head;  
    }
};
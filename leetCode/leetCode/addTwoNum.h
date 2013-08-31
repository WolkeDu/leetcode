#pragma once

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
  };

  class Solution{
  public:
	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		int precise = 10;
		ListNode* head = 0;
		ListNode* cur;
		if(l1 == 0 || l2 == 0) return head;
		int remainder = 0;
		int sum = 0;
		sum = l1->val +	l2->val;
		
		if(sum >= precise)
			remainder = sum / precise;
		else
			remainder = 0;
		head = new ListNode(sum % precise);
		cur = head;
		l1 = l1->next;
		l2 = l2->next;
		while(1){
			if(l1 == 0 || l2 == 0){
				break;
			}
			sum = l1->val +	l2->val + remainder;
			if(sum >= precise){
				remainder = sum / precise;
				
			}
			else{
				remainder = 0;
			}
			cur->next = new ListNode(sum % precise);
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}// while(1)

		if(l1 == 0){
			if(l2 == 0){
				if(remainder!=0)
					cur->next = new ListNode(remainder);
			}
			else {
				while(remainder != 0){
					if(l2 == 0){
						cur->next = new ListNode(remainder);
						break;
					}
					sum = remainder + l2->val;
					if(sum >= precise)
						remainder = sum / precise;
					else
						remainder = 0;
					cur->next = new ListNode(sum % precise);
					cur = cur->next;
					l2 = l2->next;
				}
				if(l2 != 0)
					cur->next = l2;
			}
		}
		else{ // if l1 != 0 then l2 must be 0
			while(remainder != 0){
				if(l1 == 0){
					cur->next = new ListNode(remainder);
					break;
				}
				sum = remainder + l1->val;
				if(sum >= precise)
					remainder = sum / precise;
				else
					remainder = 0;
				cur->next = new ListNode(sum % precise);
				cur = cur->next;
				l1 = l1->next;
				}
			if(l1 != 0)
				cur->next = l1;
		
		}
	  return head;
 
	 }
  
  };
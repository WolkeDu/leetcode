//Swap Nodes in Pairs
#pragma once
#include <string>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {};
 };
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *l = head;
		if(l == NULL || l -> next == NULL)
			return l;
		ListNode* r = l ->next;
		l->next = r->next; r->next = l;
		head = r;
		if(l == NULL || l->next == NULL) return head;
		ListNode* last = l;
		l = l->next; 
		r = l->next;
		while (l != NULL && r != NULL)
		{
			l->next = r->next; 
			r->next = l;
			last->next = r;
			if(l->next == NULL || l->next->next == NULL) break;
			last = l;
			l = l->next; 
			r = l->next;
			
		}
		return head;
    }
};
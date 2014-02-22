
//tion for singly-linked list.
#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {};
 };
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode* > &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main()
		auto iter = lists.begin();
		while( iter != lists.end())
			if(*iter == NULL)
				lists.erase(iter);
			else
				iter++;
		if(lists.size() == 0 ) return NULL;
		make_heap(lists.begin(),lists.end(),comp());
		ListNode* head = NULL;
		ListNode* cur = NULL;
		int last = lists.size() - 1;
		
		while(lists.size() > 0){
			if(head == NULL) cur = head = lists[0];
			else cur = cur->next = lists[0];
			pop_heap(lists.begin(),lists.end(),comp());
			last = lists.size() - 1;
			if(lists[last]->next != NULL){
			lists[last] = lists[last]->next;
			push_heap(lists.begin(),lists.end(),comp());
			}
			else
				lists.pop_back();
		}

		return head;
    }    

	class comp{
	public:
		bool operator()(ListNode* l1, ListNode* l2){
		
			return l1->val > l2->val ;
		}
	};
};

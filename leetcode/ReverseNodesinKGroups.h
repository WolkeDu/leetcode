/**
 * Definition for singly-linked list.*/
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* newhead = new ListNode(-1);
        ListNode* pre = newhead;
        pre->next = head;
        ListNode* cur = head;
        ListNode* start = head;
        ListNode* end = NULL;
        int count = 0;
        while(cur != NULL){
            count ++;
            end = cur;
            cur = cur->next;
            if(count == k){
                reverse(start,end);
                pre->next = end; pre = start;
                start = cur;
                count = 0;
            }
        }
        newhead = newhead->next;
        return newhead;
    }
    void reverse(ListNode*& start, ListNode*& end){
        ListNode* cur = start;
        ListNode* newNext = end ->next;
        ListNode* oldNext = NULL;
        while(cur!=end){
            oldNext = cur->next;
            cur -> next = newNext;
            newNext = cur;
            cur = oldNext;
        }
		cur->next = newNext;
    }
};
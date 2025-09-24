#include<bits/stdc++.h>
using namespace std;
// remove nth node from back of linked list

/**
 * can we do it in single loop ?
 * no as we have to know what is nth from start , or Size-n-1 from end ,
 * so we at least have to know about the size of linked list 
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int llSize=0;
        ListNode *temp = head;
        while(temp){
            ++llSize;
            temp=temp->next;
        }

        int ith = llSize - n;

        ListNode *prev = NULL;
        temp = head;

        if(ith == 0) {
            return head->next;
        }

        while(--ith){
            temp = temp->next;
        }
        
        temp ->next = temp->next->next;
        return head;
    }
};
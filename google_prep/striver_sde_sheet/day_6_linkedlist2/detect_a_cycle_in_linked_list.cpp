#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//so in a circle 
class Solution {
    public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        if(!slow) return false;
        if(!slow->next) return false;
        fast=fast->next->next;
        slow=slow->next;

        while(slow!=NULL && fast!=NULL){
            if(slow==fast) return true;
            slow=slow->next;
            fast= fast->next!=NULL ? fast->next->next : NULL;
        }
        return false;
    }
    };
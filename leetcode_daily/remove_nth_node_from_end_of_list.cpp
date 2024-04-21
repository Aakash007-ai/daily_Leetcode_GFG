#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//so when traversing the list using recursion
//  1 - 2 - 3 - 4 - 5
//  n=2

class Solution {
public:
    int count=0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;

        if(head->next){
            head->next = removeNthFromEnd(head->next,n);
        } //we reach at the end node
        count++;

        if(count==n){//from last we react at node which need to be skipp so we pass the address of next node
            return head->next;
        }
        
        return head;
        
    }
};
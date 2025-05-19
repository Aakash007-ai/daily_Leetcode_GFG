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

 //brute force my apprach 
 /*
 first find total length
 then mod k with length 
 then just move by n-k-1 
 and stop mark a tempHead 
 then move to tail and connect to head 
    then return tempHead
 */

 //but we can move to end find length
 // then mod the length with k
 // then attach the tail to head 
 // move head to n-k-1 and detach the tail
 // then return head


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            
        }
    };


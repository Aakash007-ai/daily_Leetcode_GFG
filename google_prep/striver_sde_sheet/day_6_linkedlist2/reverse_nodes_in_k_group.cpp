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
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

/*
    1 -> 2 -> 3 -> 4 -> 5
    k=2
    5 <- 3 <- 4 <-1 <- 2
    
    2 -> 1 -> 4 -> 3 -> 5

    //so we have to reverse every k nodes
    finally we have to return the head of the new linked list

*/
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head==NULL || head->next==NULL || k==1){
                return head;
            }

            int count = 0;
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;

            //first check if there are k nodes in the linked list
            int count = 0;
            ListNode* temp = head;
            while(temp!=NULL && count<k){
                temp = temp->next;
                count++;
            }

            if(count<k){
                return head;
            }

            //reverse k nodes
            count = 0;
            while(curr!=NULL && count<k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            //if there are more elements call for next group
            if(next!=NULL) head->next = reverseKGroup(curr,k);

            return prev;
        }
    };


    //more modular
    // class Solution {
    //     public:
    //         ListNode* reverse(ListNode* start, ListNode* end){
    //             ListNode* prev = nullptr;
    //             ListNode* curr = start;
    //             while(curr != end){
    //                 ListNode* next = curr->next;
    //                 curr->next = prev;
    //                 prev = curr;
    //                 curr = next;
    //             }
    //             return prev;
    //         }
    //         ListNode* reverseKGroup(ListNode* head, int k) {
    //             int count = 0;
    //             ListNode* temp = head;
    //             while(temp && count < k){
    //                 temp = temp->next;
    //                 count++;
    //             }
    //             if(count < k) return head;
        
    //             ListNode* new_head = reverse(head, temp);
        
    //             head->next = reverseKGroup(temp, k);
                
    //             return new_head;
    //         }
    //     };
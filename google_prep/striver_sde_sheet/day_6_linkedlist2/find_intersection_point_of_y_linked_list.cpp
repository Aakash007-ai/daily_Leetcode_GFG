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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// this is brute force apprach taking hashmap
// time complexity is O(n) and space complexity is O(n)
// class Solution {
//     public:
//         ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//             unordered_map<ListNode *, int> mp;
//             ListNode* temp = headA;
//             while (temp!=NULL){
//                 mp[temp]=temp->val;
//                 temp=temp->next;
//             }

//             temp = headB;
//             while(temp!=NULL){
//                 if(mp.find(temp)!=mp.end()){
//                     return temp;
//                 }else{
//                     temp=temp->next;
//                 }
//             }
//             return temp;
//         }
//     };


//another approach is to use 2 pointer approach
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(headA==NULL || headB==NULL){
                return NULL;
            }
            ListNode* a = headA;
            ListNode* b = headB;

            while(a!=b){
                a = (a==NULL)?headB:a->next;
                b = (b==NULL)?headA:b->next;
            }
            return a;
        }
    };




    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
         return NULL;
        }

        ListNode* a= headA;
        ListNode* b= headB;

        while(a!=b){
            //this is wrong , we are not checking if a and b are null, react to null pointer then assign to headB or headA
         a = a->next ? a->next : headB;
         b = b->next ? b->next : headA;
        }

        return a;
     }
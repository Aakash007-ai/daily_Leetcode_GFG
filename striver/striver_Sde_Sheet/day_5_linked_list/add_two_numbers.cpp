#include<bits/stdc++.h>
using namespace std;
// if there are same repetitive task with vary condition , try to reduce by muliplexing them

// or try to create a repetitive task in one go (reduce code length in one go)
// sometime in order to do higly optimised we do more complexity leading to more issue

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
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x) , next(next) {} 
 };

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *temp = l1;
//         int carry = 0;
//         while(l1 && l2){
//             int val = l1->val + l2->val + carry;
//             if(val>=10){
//                 carry = val/10;
//                 val = val%10;
//             }
//             l1->val = val;
//             l1 = l1->next;
//             l2 = l2->next;
//         }

//         while(l1){
//             int val = l1->val+carry;
//             if(val >=10){
//                 carry = val/10;
//                 val = val%10;
//             }
//             l1->val = val;
//             l1 = l1->next;
//         }

//         if(l2){
//             l1 = l2;
//         }

//         while(l1){
//             // if(!l1) l1=l2;
//             int val = l1->val+carry;
//             if(val>=10){
//                 carry = val/10;
//                 val = val%10;
//             }
//             l1->val = val;
//             l1 = l1->next;
//         }

//         if(carry !=0){
//             l1 = ListNode(carry);
//         };

//         return temp;
//     }
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};
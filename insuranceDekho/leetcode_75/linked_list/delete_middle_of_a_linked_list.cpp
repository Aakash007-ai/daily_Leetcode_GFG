#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head , *fast=head;
        ListNode *prev=NULL;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }

        if(fast->next == NULL){
            //delete that
            ListNode *temp=slow->next;
            prev->next= temp;
            delete slow;
            return head;
        }

        slow->next=slow->next->next;
        return head;
    }
};


// [1,3,4,7,1,2,6]
// 7 is mid
// fast->next 3== null slow is mid 

// [1,2,3,4]
// [1,2,4]  fast->next->next==null slow is mid->next


// [2,1] fast->next->next ==null
// [2] slow->next is mid
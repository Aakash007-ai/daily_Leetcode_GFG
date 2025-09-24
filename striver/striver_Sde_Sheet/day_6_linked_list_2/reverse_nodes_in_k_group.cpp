
/**
 * whenever something is repetitive, 
 */

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

// if you find stuck, no solution try addding another DS or extra space 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 class Solution {
public:
//     ListNode *detectCycle(ListNode *head) {
        
//     }
        ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        unordered_map<ListNode*,int> mp;
        ListNode* slow=head;
        mp[head]=0;
        int i=1;
        while(slow->next){
            slow=slow->next;
            if(mp.find(slow)==mp.end()){
                mp[slow]=i;
                i++;
            }
            else{
                return slow;
            }
        }
        return NULL;
    }
};
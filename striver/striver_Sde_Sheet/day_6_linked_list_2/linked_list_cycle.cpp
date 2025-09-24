
// always after writng solution go through it if it has many condition

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *fast = head, *slow = head;

//         if(!slow) return false;
//         if(!slow->next) return false;
//         slow=slow->next;
//         fast=fast->next->next;
        
//         while(slow && fast){
//             if(slow==fast) return true;

//             slow = slow ->next ? slow->next : NULL;
//             fast = fast->next ? fast->next->next :NULL;
//         }
//         return false;
        
//     }
// };
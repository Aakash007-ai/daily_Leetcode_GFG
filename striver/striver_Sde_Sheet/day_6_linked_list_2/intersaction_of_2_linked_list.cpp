
/**
 * always first create a suedo algo , if somehting after coding is not working , debug with an example
 */

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     if(!headA || !headB) return NULL; 

//     ListNode *itA = headA, *itB = headB;

//     while(itA != itB){
//         itA = itA ? itA->next : headB;
//         itB = itB ? itB->next : headA;
//     }
//     return itA;
//     }
// };
#include<bits/stdc++.h>
using namespace std;

// so if there is confusion in some indexing or choosing element , take a samll smaple space

// A -> B -> C -> d   (4/2 -> ans is f (0,1,2))
//   s,f   s    f

//   so while(f & f->next & & f->next->next != null) ans is f
// if(f->next) ans is s
// else ans is s->next

// A -> B -> C -> D -> E  (5/2 -> 0,1,2 ans is c)
//   s,f   s    f
//              s          f



// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *fast=head, *slow=head;
//         while(fast && fast->next && fast->next->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         if(!fast->next) return slow;
//         return slow->next;
//     }
// };
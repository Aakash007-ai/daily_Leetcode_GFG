#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// Output: [10,1,13,1000000,1000001,1000002,5]

// delete from list1
//  a=3 we have to point next to list2
//  so first decrement 3 move temp next to head   head1 a=2 -> a=1 head13 -> a=0 we cant move further
//
//  then traverse completely over list2 and point its last to
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *a_ptr = list1, *b_ptr = list1;
        while (--a)
        {
            a_ptr = a_ptr->next;
        }
        // now get b pointer
        // b_ptr   b=4 1 3-> b=3 13 2 -> b=2 6 1 -> b=1 9 0 //here list->next=b_ptr->next
        while (b--)
        {
            b_ptr = b_ptr->next;
        }

        a_ptr->next = list2;
        ListNode *temp = list2;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = b_ptr->next;
        return list1;
    }
};
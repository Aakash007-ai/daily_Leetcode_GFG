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

// 1->2->3-4->Null
// NULL<-1<-2<-3<-4

// prev = NULL;
// curr = head

// hold next of curr, then curr->next=prev , update prev=curr curr=temp->next
// temp=curr->next , curr->next=prev , prev=curr curr=temp->next,

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
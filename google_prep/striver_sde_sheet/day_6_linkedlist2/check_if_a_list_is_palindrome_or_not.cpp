#include<bits/stdc++.h>
using namespace std;

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

 //find another method

 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            vector<int> val;
            while(head){
                val.push_back(head->val);
                head=head->next;
            }
            if(val.size()==1) return true;
            for(int i=0;i<val.size()/2;i++){
                if(val[i]!=val[val.size()-1-i]) return false;
            }
            return true;
        }
    };
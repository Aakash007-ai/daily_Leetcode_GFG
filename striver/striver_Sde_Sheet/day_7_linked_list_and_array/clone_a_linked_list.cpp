#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
    public:
    int val;
    Node *next;
    Node *random;

    Node(int _val){
        this->val = val;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *oldHead = head;
        while(oldHead){
            Node *temp = new Node(oldHead->val);
            mp[oldHead] = temp;
            oldHead = oldHead->next;
        }

        Node *newHead = mp[head];
        Node *ans = mp[head];

        while(head){
            newHead->next = mp[head->next];
            newHead->random = mp[head->random];
            head = head->next;
            newHead = newHead->next;
        }
        return ans;
    }
};
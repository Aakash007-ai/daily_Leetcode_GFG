#include<bits/stdc++.h>
using namespace std;

// always check for repetitive lines in the code and replace them with single line 
// mainly occur in our code where we have if-else condition

// always handle base cases , arguments can be empty always handle them, e.g in our scenario we have added null check 

class Node {
    public:
    int val;
    vector<Node*> neighbors;
    Node(){
        int val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public:
    Node* cloneGraph(Node* node){
        unordered_map<Node*, Node*> mp;
        if(!node) return nullptr; 
        mp[node] =  new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* tempNode = q.front();q.pop();
            for(auto it: tempNode->neighbors){
                if(!mp[it]){
                    mp[it] = new Node(it->val);
                    q.push(it);
                }
                mp[tempNode]->neighbors.push_back(mp[it]); 
            }
        }
        return mp[node];
    }
};
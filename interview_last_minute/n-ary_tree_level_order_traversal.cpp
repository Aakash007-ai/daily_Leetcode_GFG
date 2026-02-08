#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// struct Node{
//     int val;
//     vector<Node*> child;
    
//     Node(){}

//     Node(int _val) : val(_val){};
//     Node(int _val, vector<Node*> _children) : val(_val), child(child){}
// };

class Node{
    public:
    int val;
    vector<Node* > children;
    
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> tempAns;
            while (n--){
                Node* node = q.front();q.pop();
                tempAns.push_back(node->val);

                for(auto it: (node->children)){
                    q.push(it);
                }
            }
            ans.emplace_back(tempAns);
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

};


/*
    we have to find minimum diff for any node minimum diff is node-itschild
    find minimum of all of this
*/

class Solution
{
    public:
    int absolute_diff(Node *root)
    {
        //we can use stack to store children and find the diff
        queue<Node*> q;
        q.push(root);
        int ans=INT_MAX;
        while(!q.empty()){
            auto node=q.front();q.pop();
            if(node->left){
                ans = min(abs(node->data - node->left->data) , ans);
                q.push(node->left);
            }

            if(node->right){
                ans = min(abs(node->data - node->right->data),ans);
                q.push(node->right);
            }
        }
        return ans;
    }
};

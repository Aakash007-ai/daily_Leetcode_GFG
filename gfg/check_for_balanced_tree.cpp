#include<bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool balanced=true;
    int solve(Node* root){
        if(root==NULL) return 0;

        int l=solve(root->left);
        int r=solve(root->right);
        
        if(abs(l-r)>=2) balanced = false;

        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int l=solve(root->left);
        int r=solve(root->right);

        if(abs(l-r)<=1) return (balanced && true);

        return false;
    }
};
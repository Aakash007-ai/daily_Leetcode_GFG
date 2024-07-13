#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
};

int solve(Node *root,int * res){
    if(root==NULL) return 0;

    int l=solve(root->left,res);
    int r=solve(root->right,res);

    // int temp = calculate temp ans
    // int ans = max(temp,relation) l+r+1
    // res = max(res,ans)

    // return temp
}
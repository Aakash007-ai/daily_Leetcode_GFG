#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    void solve(Node* root,unordered_map<string,int> &mp){
        if(root->left == NULL && root->right==NULL) return;
        string temp="";
        temp.push_back(char(root->data));
        if(root->left) {
            solve(root->left,mp);
            temp.push_back(char(root->left->data));
        }
        if(root->right) {
            temp.push_back(char(root->right->data));
            solve(root->right,mp);
        }
        mp[temp]++;
    }
    int dupSub(Node *root) {
        // code here

        unordered_map<string,int> mp;
        //we want to store every root
        solve(root,mp);
        for(auto it:mp){
            if(it.second>1) return 1;
        }
        return 0;
    }
};


// // give wrong ans for test caase, problem in our solution is that we require whole subtree must be equal not just some parts
// 3 8 8 2 3 3 1 6 8 6 4 1 6 1 3 3 7 1 1 4 2 4 8 7 5 6 7 2 5 8 1 6 3 3 1 0 5 2 3 N N N N N N N N 3 6 7 8 N N N N 5 1 1 6 2 4 0 1 7 1 4 5 3 N N N 2 3 3 1 N N N N 2 7 5 4 7 1 8 5 6 2 6 5 N N 7 8 4 6 1 2 N N N N 8 4 N N N N N N N N 5 1 5 2 N N 6 2 4 5 6 7 N N 2 4 N N N N 5 0 N N N N N N N N N N N N N N 7 1 2 5 2 0 0 4 N N N N 7 1 6 2 8 6 7 3 N N N N 1 7 7 2 2 2 N N N N N N N N N N 7 7 N N 7 1 N N N N N N 2 2 N N N N N N 4 4 3 8 0 2 1 5 2 1 8 2 7 8 4 1 N N N N 0 1 N N N N N N N N N N N N N N N N N N 1 7 N N 3 6 4 2 N N N N 2 3 5 4 1 4 N N 4 3 0 0 0 7 7 4 N N N N N N N N N N 8 8 7 4 6 2 N N 5 1 N N N N N N N N 5 0 3 6 N N N N N N N N N N 2 6 N N N N N N N N N N N N N N N N 7 3 7 6 7 5 N N N N N N N N N N N N N N N N N N
// void solve(Node* root,unordered_map<string,int> &mp){
//     if(root->left == NULL && root->right==NULL) return;
//     string temp="";
//     temp.push_back(char(root->data));
//     if(root->left) {
//         solve(root->left,mp);
//         temp.push_back(char(root->left->data));
//     }
//     if(root->right) {
//         temp.push_back(char(root->right->data));
//         solve(root->right,mp);
//     }
//     mp[temp]++;
// }
// int dupSub(Node *root) {
//     // code here

//     unordered_map<string,int> mp;
//     //we want to store every root
//     solve(root,mp);
//     for(auto it:mp){
//         if(it.second>1) return 1;
//     }
//     return 0;
// }
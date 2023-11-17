#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        right=NULL;
        left=NULL;
    }
};
class Solution{

public:
    int ans = -1;
    int floor(Node* root, int x) {
        if(!root)
            return ans;
            
        if(root->data <= x){
            ans = root->data;  // that could be my potential ans
            return floor(root->right,x);
        }
        else{
            return floor(root->left,x);
        }
    }


    // int floor(Node* root, int x) {
    //     // Code hre
    //     while(root){
    //         if(root->data==x) return x;
    //         else if(root->data>x && !root->left){
    //             return -1;
    //         }
    //         else if(root->data>x && root->left){
    //             root==root->left;
    //             continue;
    //         }
    //         else if(root->data<x && !root->right) return root->data;
    //         else if(root->data<x && root->right){
    //             root=root->right;
    //             continue;
    //         }
    //         else {
    //         }
    //     }
    // }
};





// int ans = -1;
//     int floor(Node* root, int x) {
//         if(!root)
//             return ans;
            
//         if(root->data <= x){
//             ans = root->data;  // that could be my potential ans
//             return floor(root->right,x);
//         }
//         else{
//             return floor(root->left,x);
//         }
//     }

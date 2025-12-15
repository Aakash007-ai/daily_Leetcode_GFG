#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : value(val), left(nullptr) , right(nullptr) {};
    TreeNode(int val , TreeNode *left, TreeNode *right) : value(val) , left(left) , right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while(root != nullptr || !st.empty()){
            
            while(root->left){
                st.push(root->left);
                root = root->left;
            }


            ans.push_back(root->value);
            st.pop();
            root = root-> right;
    


            

        } 
    }
};

void inorder(TreeNode * root){
    if(!root) return;
    if(root->left) inorder(root->left);
    cout<<root->value<<" ";
    if(root->right) inorder(root->right);
}
#include<bits/stdc++.h>
using namespace std;

 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public://find most frequently element in bst
    void dfs(TreeNode *root,unordered_map<int,int> &mp){
        if(!root) return;
        mp[root->val]++;
        if(root->left) dfs(root->left,mp);
        if(root->right) dfs(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        dfs(root,mp);
        int mx=INT_MIN;
        for(auto it:mp){
            mx=max(mx,it.second);
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second==mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            //we have to travers till size of queue
            int n= q.size();
            vector<int> temp;
            while(n){
                TreeNode * node = q.front();q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                n--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

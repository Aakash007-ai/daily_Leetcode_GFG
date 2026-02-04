#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode * right) : val(val) , left(left), right(right){};
};

class Solution {
public:
    vector<int> postinorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        vector<int> ans;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};
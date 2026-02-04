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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        vector<int> ans;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();st.pop();
            curr = curr->right;
        }
        return ans;
    }
};
// ----------------------------------------
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            // if (node->right) st.push(node->right);
        }
        
        // Reverse the result (modified preorder: Root→Right→Left)
        // reverse(result.begin(), result.end());
        // Now we have: Left→Right→Root
        return result;
    }
};
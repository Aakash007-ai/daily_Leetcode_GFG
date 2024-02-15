//leetcode
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

//inorder node must be in 
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* node) {
        if(!node) return ans;
 
        if(node->left) inorderTraversal(node->left);
               ans.push_back(node->val);
        if(node->right) inorderTraversal(node->right);
        return ans;
    }
};




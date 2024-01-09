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
    //inorder traversal with sum
    bool summ=false;
    int sum=0;
    //inorder left center right
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->left) rangeSumBST(root->left,low,high);
        if(root->val >= low && root->val <= high) sum+=root->val;
        if(root->right) rangeSumBST(root->right,low,high);
        return sum;
    }
};
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//we have to find maximum diameter
//find maximum of left sub tree or right sub tree and compare it with maximum


//brute force
// if node == NULL return 0
// leftHeight = solve(node->left,INT_MIN); // max height of left subtree
// rightHeight = solve(node->right,INT_MIN); //max height of right subtree
// we get leftHeight and right height,
// left+right diameter of current node //means height of
// update maxDiameer , ans = max(left+right,max);
// return max(left,right)

// class Solution {
// public:
//     int ans=INT_MIN;
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         int leftHeight = diameterOfBinaryTree(root->left);
//         int rightHeight = diameterOfBinaryTree(root->right);
//         ans= max(leftHeight+rightHeight,ans);
//         return max(leftHeight,rightHeight);
//     }
// };

class Solution {
    int diahelper(TreeNode* root,int &dia){
    if(!root) return 0;
    int lh=diahelper(root->left,dia);
    int rh=diahelper(root->right,dia);
    dia=max(dia,lh+rh);
    return max(lh,rh)+1;
}
public:
//     int diameterOfBinaryTree(TreeNode* root) {
        
//     }
    int diameterOfBinaryTree(TreeNode *root){
        int diameter=0;//o(n) o(n)
        diahelper(root,diameter);
    return diameter;
}
};
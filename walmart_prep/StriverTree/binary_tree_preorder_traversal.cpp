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

//left right then node
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* node) {
        if(!node) return ans;
        ans.push_back(node->val);
        if(node->left) preorderTraversal(node->left);
        if(node->right) preorderTraversal(node->right);
        return ans;
    }
    //variant 1
    // void solve(TreeNode * node,vector<int> & ans){
    //     if(!node) return;
    //     ans.push_back(node->val);
    //     if(node->left) solve(node->left,ans);
    //     if(node->right) solve(node->right,ans);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     solve(root,ans);
    //     return ans;
    // }
};



// // C++ program for preorder traversals

// #include <bits/stdc++.h>
// using namespace std;

// // Structure of a Binary Tree Node
// struct Node {
//     int data;
//     struct Node *left, *right;
//     Node(int v)
//     {
//         data = v;
//         left = right = NULL;
//     }
// };

// // Function to print preorder traversal
// void printPreorder(struct Node* node){
//     if (node == NULL)
//         return;

//     // Deal with the node
//     cout << node->data << " ";

//     // Recur on left subtree
//     printPreorder(node->left);

//     // Recur on right subtree
//     printPreorder(node->right);
// }

// // Driver code
// int main()
// {
//     struct Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->right = new Node(6);

//     // Function call
//     cout << "Preorder traversal of binary tree is: \n";
//     printPreorder(root);

//     return 0;
// }
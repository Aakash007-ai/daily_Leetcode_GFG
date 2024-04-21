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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth=1){
            TreeNode * head= new TreeNode(val);
            head->left=root;
            return head;
        }

        queue<TreeNode *> q;
        q.push(root);
        int h=0;--depth; //now once h==depth then start creating new row of that node with val
        while(!q.empty()){
            h++;
            int n=q.size();
            for(int i=0;i<n;i++){
                if(h==depth){
                    //now start assigning row next to queue element
                    auto node=q.front();q.pop();
                    //now put to left and right;
                    TreeNode *left = new TreeNode(val);
                    TreeNode *right = new TreeNode(val);

                    left->left = node->left ? node->left : NULL;
                    right ->right = node->right ? node->right :NULL;

                    node->left = left;
                    node->right = right; 
                }else{
                    auto node=q.front();q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }
        return root;
    }
};
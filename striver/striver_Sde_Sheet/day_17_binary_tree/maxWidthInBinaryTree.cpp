#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// max width between 2 leftmmost and right most nodes at any level, at each level
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode *,long>> q;
        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){
            int n = q.size();
            int currLeftMin = INT_MAX; 
            int currRightMax = INT_MIN;

            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                int w = q.front().second;
                q.pop();

                currLeftMin = min(currLeftMin,w);
                currRightMax = max(currRightMax,w);

                if(node->left){
                    q.push({node->left,w-1});
                }

                if(node->right){
                    q.push({node->right,w+1});
                }
            }

            ans = max((int)ans, currRightMax-currLeftMin);
        }
        return ans;
    }
};




#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// max width between 2 leftmmost and right most nodes at any level, at each level
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode *,long long>> q;
        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){
            int n = q.size();
            long long leftMost = q.front().second;
            long long rightMost = q.front().second;

            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - leftMost;
                q.pop();

                rightMost = idx;

                if(node->left){
                    q.push({node->left,2*idx});
                }

                if(node->right){
                    q.push({node->right,2*idx +1});
                }
            }

            ans = max(ans,rightMost+1);
        }
        return ans;
    }
};
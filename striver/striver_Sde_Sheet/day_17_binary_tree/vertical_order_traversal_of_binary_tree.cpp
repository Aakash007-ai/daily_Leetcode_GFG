#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#define pni pair<TreeNode *,TreeNode>

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;
        
        queue<tuple<TreeNode*, int, int>> q; // node, vertical position, level
        // or
        // queue<pair<TreeNode*, pair<int, int>>> q; // node, column, row
        q.push({root, 0, 0});
        int wMin = INT_MAX, wMax = INT_MIN;
        
        while(!q.empty()){
            auto [node, col, level] = q.front();
            q.pop();
            mp[col][level].insert(node->val);
            wMin = min(wMin, col);
            wMax = max(wMax, col);
            
            if(node->left){
                q.push({node->left, col-1, level+1});
            }
            
            if(node->right){
                q.push({node->right, col+1, level+1});
            }
        }

        for(int i=wMin; i<=wMax; i++){
            for(auto& [level, values] : mp[i]){
                for(int val : values){
                    ans.back().push_back(val);
                }
            }
            if(!mp[i].empty()){
                ans.push_back({});
            }
        }
        
        if(!ans.empty() && ans.back().empty()){
            ans.pop_back();
        }

        return ans;
    }
};
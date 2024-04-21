#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         int n=nums.size();
//         unordered_map<int,vector<int>> mp(n);
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<nums[i].size();j++){
//                 mp[i+j].push_back(nums[i][j]);
//             }
//         }
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             ans.insert(ans.size(),mp[i].begin(),mp[i].end());
//         }     
//     }
// };

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        
        while (groups.find(curr) != groups.end()) {
            for (int num : groups[curr]) {
                ans.push_back(num);
            }
            
            curr++;
        }
        
        return ans;
    }
};

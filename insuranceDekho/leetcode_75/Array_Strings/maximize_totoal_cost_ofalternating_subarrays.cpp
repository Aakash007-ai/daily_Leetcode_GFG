#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long solve(vector<int> nums,int i,bool prevNeg){
//         if(i==nums.size()){
//             return 0;
//         }

//         if(nums[i]<0){
//             //we have choice to choose it neg or or make it positive
//             //prevNeg is  false means prev element is +v and we can turn  this neg to positive or we just skip it
//             if(!prevNeg) return max(nums[i] + solve(nums,i+1,prevNeg),-1*nums[i]+solve(nums,i+1,!prevNeg));
//             else return -1*nums[i]+solve(nums,i+1,!prevNeg);
            
//         }
//      return nums[i]+solve(nums,i+1,prevNeg);

//     }
//     long long maximumTotalCost(vector<int>& nums) {
//         return solve(nums,0,false);
//     }
// };


class Solution {
public:
    long long solve(vector<int> nums,int i,bool prevNeg,vector<vector<long long>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prevNeg]!= -1) return dp[i][prevNeg];

        if(nums[i]<0){
            //we have choice to choose it neg or or make it positive
            //prevNeg is  false means prev element is +v and we can turn  this neg to positive or we just skip it
            if(!prevNeg) return dp[i][prevNeg]=max(nums[i] + solve(nums,i+1,prevNeg,dp),-1*nums[i]+solve(nums,i+1,!prevNeg,dp));
            else return dp[i][prevNeg]=-1*nums[i]+solve(nums,i+1,!prevNeg,dp);
            
        }
     return dp[i][prevNeg]=nums[i]+solve(nums,i+1,prevNeg,dp);

    }
    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long> (2,-1));
        return solve(nums,0,false,dp);
    }
};


int main() {
    vector<int> nums1 = {1, -2, 3, 4};
    vector<int> nums2 = {1, -1, 1, -1};
    vector<int> nums3 = {0};
    vector<int> nums4 = {1, -1};
    Solution obj;

    cout << obj.maximumTotalCost(nums1) << endl; // Output: 10
    cout << obj.maximumTotalCost(nums2) << endl; // Output: 4
    cout << obj.maximumTotalCost(nums3) << endl; // Output: 0
    cout << obj.maximumTotalCost(nums4) << endl; // Output: 2

    return 0;
}
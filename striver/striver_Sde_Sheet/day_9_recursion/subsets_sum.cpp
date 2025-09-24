#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // vector<int> ans;
    // int tempSum = 0;
    void solve(vector<int> &nums, int n,vector<int> &ans , int sum=0){
        if(n==0){
            ans.push_back(sum);
            return;
        }
        solve(nums,n-1,ans,sum);
        solve(nums,n-1,ans,sum+nums[n-1]);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        solve(nums,nums.size(),ans);
        return ans;
    }
};
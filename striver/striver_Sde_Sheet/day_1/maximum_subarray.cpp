#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int prefixSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum);

            if(prefixSum < 0){
                prefixSum = 0;
            }
        }      
        return maxSum;
    }
};
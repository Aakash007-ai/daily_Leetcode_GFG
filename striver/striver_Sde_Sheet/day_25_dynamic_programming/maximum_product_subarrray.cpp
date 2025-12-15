#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftMax = INT_MIN, rightMax = INT_MIN, currLeft = 1, currRight = 1;
        for(int i=0;i<n;i++){
            currLeft*=nums[i];
            leftMax = max(leftMax, currLeft);
            if(currLeft == 0) currLeft = 1;
        }

        for(int j=n-1;j>=0;j--){
            currRight *= nums[j];
            rightMax = max(rightMax, currRight);
            if(currRight == 0) currRight = 1;
        }

        return max(leftMax, rightMax);
    }
};
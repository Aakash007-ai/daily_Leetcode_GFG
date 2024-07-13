#include<bits/stdc++.h>
using namespace std;

// Input: nums = [0,1,1,1,0,0]
// Output: 3

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flip=0;
        for(int i=0;i<n-3;i++){
            if(nums[i]==0){
                flip++;
                nums[i]!=nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        return flip;
        //sliding window of size 3
        // int i=0,j=0;
        // int n=nums.size();
        // int ones=0;
        // int zeroes=0;
        // while(j<n){

            // if(nums[j]==0) zeroes++;
            // if(nums[j]==1) ones++;
            // if(j-i+1<3){//window still not formed
            //     j++;
            //     continue;
            // }    
    }
};
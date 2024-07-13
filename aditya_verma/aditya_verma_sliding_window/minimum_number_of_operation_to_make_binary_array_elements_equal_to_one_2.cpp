#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        //find first 0 and revert nex
        int n=nums.size();
        int ans=0;
        int flipCount=0;
        for(int i=0;i<n;i++){
            if(flipCount%2){
                //means no flip happenwe can treate element as usual
                nums[i]=!nums[i];//we get the final flipped
            }

            if(nums[i]==0){
                ans++;
                flipCount++;
            }
        }
    }
};
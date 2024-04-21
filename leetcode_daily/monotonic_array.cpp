#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            if(nums[i+1] > nums[i]){
                dec = false;
            }
            else if(nums[i+1] < nums[i]){
                inc = false;
            }
        }
        if(inc || dec){
            return true;
        }
        return false;
    }
};
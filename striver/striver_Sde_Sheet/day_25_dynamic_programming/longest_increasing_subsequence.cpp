#include<bits/stdc++.h>
using namespace std;


/**
 * let's do a agile approach
 * using recursion,
 * 
 * first find base condition
 * 
 * then choice + sub problems 
 */


// ----------- Brute force try ---------------------------------------------
int lis(vector<int> &nums, int n = 0 , int last = -1){
    if(n == 0) return 0;
    int left = INT_MIN;
    int right = INT_MIN;
    if(last == -1){
        n = nums.size();
        int lastEle = nums[n-1];
        left = lis(nums,n-1,lastEle)+1;
    }else{
        if(last > nums[n-1]){
            left = lis(nums,n-1, nums[n-1]) + 1;
        }else{
            left = lis(nums, n-1, last);
        }
    }

    right = lis(nums, n-1, last);
    return max(left,right);
}

 /**
  * 
  * left + right, 
  * don't get confused in left or right ,  left means include (if allowd), right means to skip
  * 
  * instead of taking element take last as prevIdx,
  * 
  * we have mixed driver function + recusive call at statement re-defining n = nums.size()
  */

class Solution {
public:
    int solve(vector<int>& nums, int idx, int prevIdx) {
        if (idx == nums.size()) return 0;

        int len = solve(nums, idx+1, prevIdx);

        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            len = max(len, 1 + solve(nums, idx+1, idx));
        }

        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};

/**
 * now bottom up approach , check changing factor
 * its idx -> 0 to size , prevIdx 0 to Size-1
 * create vector of this size()
 */

class Solution {
public:
    int lis(vector<int> &nums, int n = 0 , int last = -1){
        if(n == 0) return 0;

        int left = INT_MIN;
        int right = INT_MIN;
        // we have two choice we have an element to pick and compare either pick or 
        if(last == -1){ // element not choosen right now , either choose or skip
            //choose
            n = nums.size();
            int lastEle = nums[n-1];
            left = lis(nums,n-1,lastEle)+1;
        }else{ // we have already a number to compare
            if(last > nums[n-1]){ // if it is greater than curr
                left = lis(nums,n-1, nums[n-1]) + 1;
            }
             //then don't have option to choose   
        }

        right = lis(nums, n-1, last);
        return max(left,right);
    }
};


class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(auto it:nums){
            auto itr = lower_bound(tails.begin(),tails.end(),it);
            if(itr == tails.end()){
                tails.push_back(it);
            }else{
                *itr = it;
            }
        }
        return tails.size();
    }
};




#include<bits/stdc++.h>
using namespace std;


//a new way of solving problem , you know some cases

/*
    so maximum subarray
    if all number is +ve then, then sum of all elements means for loop over all element

    if there is any -ve in between , and sum of all elements is +ve than any subarray
    again sum of all subarray

    if due to any -ve no. -the sum become -ve and it may be possible that next subarray is +ve
    then we have to restart sum

    if all are -ve then, find max of all, rather than sum 
*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int n=nums.size();
        int tempSum=0;
        for(int i=0;i<n;i++){
            tempSum+=nums[i];

            maxSum = max(tempSum,maxSum);
            if(tempSum<0){
                tempSum=0;
            }

            maxSum = max(nums[i],maxSum);
        }
        return maxSum;
    }
};
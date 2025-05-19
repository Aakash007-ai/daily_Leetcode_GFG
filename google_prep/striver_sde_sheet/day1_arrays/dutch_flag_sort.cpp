#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int i=0,j=-1,k=nums.size()-1;
    //     while(true && k>=i){
    //         //if all are 2 we just decrement k and finally it swap over i and we break over rule
    //         if(nums[i]==2){
    //             swap(nums[i],nums[k--]);
    //             continue;
    //         }else if(nums[k]==0){
    //             swap(nums[i++],nums[j]);
    //         }
    //         else if(nums[k]==2){
    //             k--;
    //         }
    //         else if(nums[i]==1){
    //             if(j==-1){
    //                 j=i; //we got our first 1 to replace with 0 later
    //             }else if(nums[i]){
                    
    //             }
    //         }
    //     }
    // }

    // i pointing to to next of zeroes of 1, j end of i (last 0), k the last index
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(i<=k){
            if(nums[i]==2){
                swap(nums[i],nums[k--]);
            }else if(nums[i]==0){
                swap(nums[i],nums[j++]);
                if(nums[i]==0){
                    i++;
                }
            }else {
                i++;
            }
        }
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int k=0;
        while(k<=j){
            if(nums[k]==0){//put it behind k
                swap(nums[i++],nums[k]);
                if(nums[k]==0){
                    k++;
                }
            }
            else if(nums[k]==2){
                swap(nums[k],nums[j--]);
            }else{
                k++;
            }          
        }
    }
};
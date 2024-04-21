#include<bits/stdc++.h>
using namespace std;

//start i from end if arr[i-1]<arr[i]
// swap(arr[i],arr[i-1]) and sort() rest of index

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool isSorting=false;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                //find the element bigger than arr[i-1] and lesser than arr[i]
                if(i!=nums.size()-1){
                    //swap next greater element than of nums[i-1]and less of nums[i]
                }else{
                    //just swap
                }
                //swap(nums[i],nums[i-1]);
                if(i!=nums.size()-1){//dont sort if current element is at last index else sort
                    sort(nums.begin()+i+1,nums.end());
                }
                isSorting=true;//as if even swip is there don't sort then
                break;
            }
        }
        if(!isSorting) sort(nums.begin(),nums.end());
    }
};
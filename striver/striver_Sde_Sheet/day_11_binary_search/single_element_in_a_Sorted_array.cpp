#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int singleNonDuplicate(vector<int>& nums) {
    //     int prefix = nums[0];
    //     int n = nums.size();
    //     for(int i=1;i<n;i++){
    //         prefix^=nums[i];
    //     }
    //     return prefix;
    // }

        int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, end = n-1;
        while(low<end){
            int mid = (low+end)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid] == nums[mid-1])){
                low = mid+1;
            }else{
                end = mid;
            }
        }
        return nums[low];
    }
};
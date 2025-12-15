#include<bits/stdc++.h>
using namespace std;

/**
 * Approach 
 * since it is sorted but the heck is it is rotated
 * so we first find which side is properly sorted , left or right then search in sorted area,
 * if it is not in sorted area, move to unsorted area
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, end = n-1;
        while(low<=end){
            int mid = (low+end)/2;
            if(target==nums[mid]) return mid;
            // which half is sorted
            if(nums[mid] >= nums[low]){ // left is sorted
                if(target < nums[mid] && target>= nums[low]) end = mid-1;
                else low = mid+1;
            }else{ //right is sorted
                if(target > nums[mid] && target <= nums[end]) low = mid+1;
                else end = mid-1;
            }
        }
        return -1;
    }
};

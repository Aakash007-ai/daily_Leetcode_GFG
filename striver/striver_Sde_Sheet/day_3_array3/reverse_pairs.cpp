#include<bits/stdc++.h>
using namespace std;

// try this again later

// so it is just like inversion count , finding number of where for 0<=i<j where arr[i]>arr[j] , merge sort array simply

/**
 * Merge Sort , divide and conquer
 * 
 * so we took i and j pointing to starting and ending index , we take mid = i+j/2, then 0 to mid, mid+1 to j, call for same to sort 
 */
class Solution {

    int merge(int s, int mid,int e, vector<int>& nums){
        
        int count=0;
        
        if(s >= e) return 0;
        //do in-place sort
        // int i=s, j=mid+1;
        // while(i <= mid && j<= e){
        //     if(nums[i]<nums[j]){
        //         i++;
        //     }else if(nums[j]>nums[i]){
        //         if(nums[j] > 2*nums[i]){
        //             count++;
        //         }
        //         swap(nums[j],nums[i]);
        //         i++;
        //     }
        // }


        int j = mid + 1;
        for(int i=s;i<=mid;i++){
            while(j<=e && (long long)nums[i] > 2LL * nums[j]){
                j++;
            }
            count += (j-mid+1);
        }


        // Now merge the two sorted halves
        vector<int> temp;
        int left = s, right = mid + 1;
        while (left <= mid && right <= e) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= e) temp.push_back(nums[right++]);

        for (int k = s; k <= e; k++) {
            nums[k] = temp[k - s];
        }
        return count;
    }

    int mergeSort(int s, int e, vector<int>& nums){
        if(s>=e){
            return 0;
        };

        int ans = 0;

        int mid = s + (e-s)/2;

        ans += mergeSort(s,mid,nums);
        ans += mergeSort(mid+1, e, nums);

        //now merge it
        ans += merge(s,mid,e,nums);
        return ans;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);     
    }
};
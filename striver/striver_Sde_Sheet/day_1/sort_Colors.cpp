#include<bits/stdc++.h>
using namespace std;


/** 012 dutch flag 2 pointer problem
 * assume we have some index i,j,k
 * i pointing to upper bound of 0,
 * j pointing to lower bound of 2
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0, j = nums.size()-1, k=0;
        while(k<n && k <= j){
            if(nums[k] == 0){
                swap(nums[i++],nums[k++]);
                continue;
            }
            if(nums[k] == 2){
                swap(nums[k], nums[j--]);
                continue;
            }
            if(nums[k]==1){
                k++;
            }
        }    
    }
};
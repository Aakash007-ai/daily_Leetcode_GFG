#include<bits/stdc++.h>
using namespace std;

// there is another way of 2 sum without any extra space
// by sorting arrays then 2 pointer algo , one starting from start, another starting from end


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp(n);

        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                return {mp[nums[i]],i};
            }else{
                mp[target - nums[i]] = i;
            }
        }
        return {};
    }
};
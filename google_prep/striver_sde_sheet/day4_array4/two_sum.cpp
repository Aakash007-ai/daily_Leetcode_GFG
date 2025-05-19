#include<bits/stdc++.h>
using namespace std;

// we are given a target and we have to find the 2 index where ele sum up to target
//hash map

//noraml aaproach
/*
    use a hash map to store no.
*/

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> mp;
            for(int i=0;i<nums.size();i++){
                //find in hash map
                if(mp.find(nums[i])!= mp.end()){
                    return {mp[nums[i]],i};
                }else {
                    mp[target-nums[i]] = i;
                }
            }
            return {-1,-1}; //not found
        }
    };
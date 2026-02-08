#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int j =0;
        int n = nums.size();
        vector<int> ans;
        map<int,int,greater<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;

            if(i-j+1 > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }

            if(i-j+1 == k){
                // compute ans
                ans.push_back(mp.begin()->first);
            }
        }
        return ans;
    }
};
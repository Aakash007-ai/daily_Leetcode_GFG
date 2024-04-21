#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            ans+=(it.second*(it.second-1))/2;
        }
        return ans;
    }
};
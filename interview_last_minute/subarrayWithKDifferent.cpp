#include<bits/stdc++.h>
using namespace std;
https://leetcode.com/discuss/post/7329731/15-dp-variations-for-interviews-by-indup-q8o7/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int j = 0;
        int n = nums.size();
        int ans =0;
        // unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            
            if(mp.size() == k){
                ans++;
            }
        }
    }
};
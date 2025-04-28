#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the majority elements in the array
      vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        
        int check=arr.size()/3;
        vector<int> ans = {};
        for(auto it:mp){
            if(it.second > check) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
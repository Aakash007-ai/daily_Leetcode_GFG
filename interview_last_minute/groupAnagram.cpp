#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp; 
        for(auto it: strs){
            string temp = it;
            sort(temp.begin(),temp.end());
            if(mp.find(temp) != mp.end()){
                mp[temp].push_back(it);
                continue;
            }
            mp[temp].push_back(it);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }

        unordered_set<int> st;
        for(auto it:mp){
            if(st.count(it.second)==1){
                return false;
            }else{
                st.insert(it.second);
            }
        }
        return true;
    }
};
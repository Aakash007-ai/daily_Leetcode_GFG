#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> mp;
        int n=s.size(), m = t.size();
        if(n!=m) return false;
        while(n>=0 || m >=0){
            if(n--) mp[s[n]]++;
            if(m--) mp[t[m]]--;
        }   

        for(auto it:mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
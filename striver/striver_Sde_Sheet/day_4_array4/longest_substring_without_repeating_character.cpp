#include<bits/stdc++.h>
using namespace std;

// improve it further

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int k=0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            auto it = mp.find(s[i]);
            if(it == mp.end()){
                mp[s[i]] = i;
                maxLen = max(maxLen, i-k+1);
            }else{
                while(s[k]!=s[i]){
                    mp.erase(s[k++]);
                }
                mp.erase(s[k++]);
                mp[s[i]]=i;
            }
        }   
        return maxLen;
    }
};
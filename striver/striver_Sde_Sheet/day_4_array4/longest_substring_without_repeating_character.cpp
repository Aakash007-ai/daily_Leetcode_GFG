#include<bits/stdc++.h>
using namespace std;


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
                // we know at what idx we have that ele
                while(s[k]!=s[i]){ //reset index
                    mp.erase(s[k++]); // remove that element from map and update map
                }
                mp[s[i]]=i;
            }
        }   
        return maxLen;
    }
};
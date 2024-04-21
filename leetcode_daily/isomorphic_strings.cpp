#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                //element is ther in map just comapre
                if(mp[s[i]]!= t[i]) return false;
            }
            else{
                mp[s[i]]=t[i];
            }
        }

        unordered_map<char,char> mp1;
        for(int i=0;i<s.size();i++){
            if(mp.find(t[i]) != mp.end()){
                //element is ther in map just comapre
                if(mp[t[i]]!= s[i]) return false;
            }
            else{
                mp[t[i]]=s[i];
            }
        }
        return true;
    }
};
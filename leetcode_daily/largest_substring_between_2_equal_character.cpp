#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int i=0;
        int mx=INT_MIN;
        for(auto it:s){
            auto itr= mp.find(it);
            if(itr==mp.end()){
                //means no match found lets continue and add it to map
                mp[it]=i;

            }else{
                //we have a match get its index and find min
                mx = max(mx,i-itr->second-1);
            }
            i++;
        }
    }
};
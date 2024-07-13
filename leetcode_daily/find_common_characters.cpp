#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) { 
        vector<int> chars(26,0);
        for(int i=0;i<words.size();i++){
            for(auto it:words[i]){//iterating over each character
                if(chars[it-97]==i){
                    chars[it-'a']++;// if index == number we increment onlythat
                }
            }
        }
        int n=words.size()-1;
        vector<string> ans;
        for(int i=0;i<26;i++){
            if(chars[i]==n){
                ans.push_back(to_string(char(i+'a')));
            }
        }
        return ans;
    }
};
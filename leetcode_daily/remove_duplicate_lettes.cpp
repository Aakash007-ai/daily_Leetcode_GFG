#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//using constraints lower case a=97
//A = 97-32 = 45
    string removeDuplicateLetters(string s) {
        vector<int> ch(25,0);
        for(auto c:s){
            ch[c-97]++;
        }
        string ans="";
        for(int i=0;i<25;i++){
            if(ch[i]) ans.push_back(i+97);
        }
        return ans;
    }
};
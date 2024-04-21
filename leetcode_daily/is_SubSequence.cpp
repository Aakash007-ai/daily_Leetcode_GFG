#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,n=s.length();
        for(auto it:t){
            if(i==n) return true;
            if(s[i]==it) i++;
            //incase we have match earlier no need to traverse over next elelments
        }
        return false;
    }
};
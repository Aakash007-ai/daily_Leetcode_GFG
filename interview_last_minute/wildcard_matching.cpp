#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
    }


    // recursion
    bool solve(string& s, string& p, int i,int j){
        if(i<0 || j<0) return true;
        if(i >= 0 && j<0) return false;
        
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j--] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j]=='?') return solve(s,p,i-1,j-1);

        if(p[j] == '*') return solve(s,p,i-1,j) || solve(s,p,i,j-1);
        return false;
    }
    
    bool isMatch(string s, string p) {
        return solve(s,p, s.size()-1, p.size()-1);
    }
};
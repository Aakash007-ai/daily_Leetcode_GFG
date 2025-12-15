#include<bits/stdc++.h>
using namespace std;


/**
 * try to write clean code while coding also, try dynamic way
 */
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(auto it:s){
            switch(it){
                case 'I':
                    ans+=1;
                    break;
                case 'V':
                    ans+=5;
                    break;
                case 'X':
                    ans+=10;
                    break;
                case 'L':
                    ans+=50;
                    break;
                case 'C':
                ans+=100;
                break;
                case 'D':
                ans+= 500;
                break;
                case 'M':
                ans+= 1000;
                break;
                default :
                ans+=0;
            }
        }
        return ans;
    }
};



// clean solution
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I', 1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}
        };
        int n = s.size();
        int ans = 0;
        for(int i = n; i>=0 ; i--){
            if(i+1 < n && mp[s[i]] < mp[s[i+1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }
        return ans;
    }
};
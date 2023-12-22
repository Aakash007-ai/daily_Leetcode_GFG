#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        //count zero from left and ones from right
        int ones=0;
        int zeroes=0;
        for(auto it:s){
            if(it='1') ones++;
        }
        int mx=INT_MIN;
        for(auto it:s){
            if(it='0') zeroes++;
            else if(it='1') ones--;

            mx=max(mx,ones+zeroes);
        }
        return mx;
    }
};
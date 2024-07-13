#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=s.size();
        int j=i;
        while(i>=0){
            if(s[i]==' '){
                //reverse string
                string temp(s.begin()+i,s.begin()+j);
                temp;
                ans+=temp
            }
        }
    }
};
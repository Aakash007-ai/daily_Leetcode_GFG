#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        string str="0";
        int mx=1;
        for(int i=1;i<n;i++){
            if(str[mx-1]=='0'){
                str.push_back('1');
                mx++;
            }
            else{
                str.push_back('1');
                str.push_back('0');
                mx +=2;
            }
        }
        
    }
};
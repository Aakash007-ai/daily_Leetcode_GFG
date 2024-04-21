#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.n
    string decimalToBinary(int n){
        string ans="";
        if(n==0) return "0";
        if(n==1) return "1";
        while(n){
            if(n%2==0){
                ans.push_back('0');
            }else{
                ans.push_back('1');
            }
            n/=2;
        }
        reverse(ans.begin(),ans.end());

        return ans; 
    }
    string binaryToGray(string s){
        string ans="";
        ans.push_back(*s.begin());
        for(int i=1;i<s.size();i++){
            ans.push_back(char((ans[i-1]-'0')^int(s[i])));
        }
        return ans;
    }

    int binaryToDecimal(string s){
        int ans=0;
        int n=s.size();
        for(int i=s.size();i>=0;i--){
            
        }
    }

    int grayToBinary(int n){      
        // Your code here
        string s = decimalToBinary(n);

        string t= binaryToGray(s);

        int ans = binaryToDecimal(t);
    }
};
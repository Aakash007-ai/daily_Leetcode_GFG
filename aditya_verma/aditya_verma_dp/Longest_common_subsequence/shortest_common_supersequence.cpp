#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //top down
    vector<vector<int>> longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp;
    }

    void printLCS(string text1, string text2){
        vector<vector<int>> dp = longestCommonSubsequence(text1,text2);

        string lcs = "";
        int n = text1.size(), m = text2.size();
        while(n>0 && m>0){
            if(text1[n-1]== text2[m-1]){
                lcs.push_back(text1[n-1]);
                n--;m--;
            }else if(dp[n-1][m] > dp[n][m-1]){
                lcs.push_back(text1[n-1]);
                n--;
      
            }else{
                lcs.push_back(text2[m-1]);
                m--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout<<"LCS is "<<lcs; 
    }
};
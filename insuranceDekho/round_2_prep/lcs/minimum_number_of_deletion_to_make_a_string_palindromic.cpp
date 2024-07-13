#include<bits/stdc++.h>
using namespace std;

int minDeletions(string A, int n) { 
        string B(A.begin(),A.end());
        reverse(B.begin(),B.end());
        int m=n;
        // now find lcs between both
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
} 
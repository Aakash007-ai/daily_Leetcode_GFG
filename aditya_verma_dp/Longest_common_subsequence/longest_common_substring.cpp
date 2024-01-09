#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
            // int m=S1.size(),n=S2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        int mx=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(S2[i-1]==S1[j-1]){
                     dp[i][j]=dp[i-1][j-1]+1;
                     mx=max(dp[i][j],mx);
                }
                else{
                    dp[i][j]=1;
                    
                    // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return mx;
    
    }
};


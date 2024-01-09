#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //top down
    int longestCommonSubsequence(string text1, string text2) {
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
        
        return dp[m][n];
    }


    // //memoization
    // int solve(int m,int n,string x,string y,vector<vector<int>> &dp){
    //     if(m==0 || n==0) return 0;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     if(x[m-1]==y[n-1]) return dp[m][n]=solve(m-1,n-1,x,y,dp)+1;
    //     return dp[m][n]=max(solve(m-1,n,x,y,dp),solve(m,n-1,x,y,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
    //     return dp[text1.size()][text2.size()]=solve(text1.size(),text2.size(),text1,text2,dp);
    // }





//  recursion
//     int solve(int m,int n,string x,string y){
//         if(m==0 || n==0) return 0;
//         if(x[m-1]==y[n-1]) return solve(m-1,n-1,x,y)+1;
//         return max(solve(m-1,n,x,y),solve(m,n-1,x,y));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         return solve(text1.size(),text2.size(),text1,text2);
//     }
};
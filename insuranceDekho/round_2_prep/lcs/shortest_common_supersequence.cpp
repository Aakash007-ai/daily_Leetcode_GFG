#include<bits/stdc++.h>
using namespace std;

/*
    shortest common supersequence
    so, we a net string  which has a subsequence of s1 and s2
    so if we know subsequence of s1 and s2 it means these characters are common
    so length of s1-subsequence + length of s1- subsequence +sbsequence
*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int n, int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return X.size()+Y.size()-dp[n][m];
    }
};

int main(){
    string x,y;
    cin>>x>>y;
    Solution obj;
    cout<<obj.shortestCommonSupersequence(x,y,x.size(),y.size());
}
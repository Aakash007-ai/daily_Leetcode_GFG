#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*
    longest palindromic subsequence abcba  whose half is equal and mirror
    
*/

class Solution{
  public:
    int longestPalinSubseq(string A) {
        string B(A.begin(),A.end());
        reverse(B.begin(),B.end());

        int n=A.size();
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
        return dp[n][n];
    }
};

int main(){
    string x;
    cin>>x;
    Solution obj;
    cout<<obj.longestPalinSubseq(x);
}
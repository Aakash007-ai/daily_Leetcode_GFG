#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int longestCommonSubstring(string str1, string str2, int n, int m) {
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return mx;
    }
};

int main(){
    int n;cin>>n;
    string s1;
    cin>>s1;
    int m;cin>>m;
    string s2;
    cin>>s2;
    Solution obj;
    cout<<obj.longestCommonSubstring(s1,s2,n,m);
}
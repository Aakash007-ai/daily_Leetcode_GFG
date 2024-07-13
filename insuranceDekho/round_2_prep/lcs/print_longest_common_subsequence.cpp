#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=n,j=m;
        string ans="";
        while(i || j){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;j--;
            }else{
                if(i>0 && dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

        return dp[n][m];
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
    cout<<obj.lcs(n,m,s1,s2);
}
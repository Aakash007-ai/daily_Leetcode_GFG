#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
    given 2 string of 2 different length or same length
    find the length of longest common subsequence

    subsequence means may not adjacent

    base condition if any of them is empty return 0 we can't comapre
    
    so compare last character if equal then 1+ solve for next 
    if not equal then compare one with one less of other

*/

// class Solution {
//   public:
//     // Function to find the length of longest common subsequence in two strings.
//     int lcs(int n, int m, string str1, string str2) {
//         if(n==0 || m==0) return 0;
//         if(str1[n-1]==str2[m-1]){
//             return 1+lcs(n-1,m-1,str1,str2);
//         }
//         return max(lcs(n-1,m,str1,str2),lcs(n,m-1,str1,str2));
//     }
// };

// int main(){
//     int n;cin>>n;
//     string s1;
//     cin>>s1;
//     int m;cin>>m;
//     string s2;
//     cin>>s2;
//     Solution obj;
//     cout<<obj.lcs(n,m,s1,s2);
// }


//memoization
// static int dp[1001][1001];

// class Solution {
//   public:
//   Solution(){
//     memset(dp,-1,sizeof(dp));
//   }
  
//     // Function to find the length of longest common subsequence in two strings.
//     int lcs(int n, int m, string str1, string str2) {
//         if(n==0 || m==0) return 0;

//         if(dp[n][m]!= -1) return dp[n][m];

//         if(str1[n-1]==str2[m-1]){
//             return dp[n][m]=1+lcs(n-1,m-1,str1,str2);
//         }
//         return dp[n][m]=max(lcs(n-1,m,str1,str2),lcs(n,m-1,str1,str2));
//     }
// };


//top down

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
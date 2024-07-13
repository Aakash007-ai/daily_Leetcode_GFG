#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{   
public:
    int findMinInsertions(string str1){
        //find longest common subsequence then length-lcs = ans
        string str2(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        int n=str1.size();
        int m=n;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        //we have length of max palindromic subsequence length
        return n-dp[n][n];

    }
};

int main(){

}
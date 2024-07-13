#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str1){
		// Code here
        int n=str1.size();
        string str2(str1.begin(),str1.end());
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1] && i!=j){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
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
    cout<<obj.LongestRepeatingSubsequence(x);
}
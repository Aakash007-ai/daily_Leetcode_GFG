#include<bits/stdc++.h>
using namespace std;



class Solution{
public:
    int solve(int arr[],int n,int sum){
        vector<vector<int>> dp(n+1, vector<int> (sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[]){
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!= 0) return 0;

        int ans = solve(arr,N,sum/2);
        return ans;
    }
};

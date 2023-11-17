#include<bits/stdc++.h>
using namespace std;

//brute flow
// class Solution{
// 	public:
//     bool solve(int arr[], int sum,int n){
//         //int n=arr.size();
//         vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
//         // for(int i=0;i<=sum;i++){
//         //     dp[0][i]=0;
//         // }
//         for(int j=0;j<=n;j++){
//             dp[j][0]=1;
//         }
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=sum;j++){
//                 if(arr[i-1]>j){
//                     dp[i][j]=dp[i-1][j];
//                     continue;
//                 }
//                 dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
//             }
//         }
//         return dp[n][sum];
//     }
//     int perfectSum(int arr[], int n, int sum){
//         return solve(arr,sum,n);
// 	}	  
// };



class Solution{
	public:
    //memoization, bottom up
    int solve(int arr[],int n,int sum,vector<vector<unsigned int>> &dp){
        if(sum==0 && n==0) return 1; //become invalid when there is ar[i] =0
        if(n==0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(arr[n-1]>sum) return dp[n][sum]=solve(arr,n-1,sum,dp);

        return dp[n][sum]=solve(arr,n-1,sum-arr[n-1],dp) + solve(arr,n-1,sum,dp);
    }

	int perfectSum(int arr[], int n, int sum){
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int> (sum+1 ,-1));
        return solve(arr,n,sum,dp);
	}

    //memoization , bottom up //input is too large
    // int solve(int arr[],int n,int sum,vector<vector<int>> &dp){
    //     if(sum==0 && n==0) return 1; //become invalid when there is ar[i] =0
    //     if(n==0) return 0;
    //     if(dp[n][sum]!=-1) return dp[n][sum];
    //     if(arr[n-1]>sum) return dp[n][sum]=solve(arr,n-1,sum,dp);

    //     return dp[n][sum]=solve(arr,n-1,sum-arr[n-1],dp) + solve(arr,n-1,sum,dp);
    // }

	// int perfectSum(int arr[], int n, int sum){
    //     vector<vector<int>> dp(n+1,vector<int> (sum+1 ,-1));
    //     return solve(arr,n,sum,dp);
	// }

    //recursion
    //int solve(int arr[],int n,int sum){
    //     if(sum==0 && n==0) return 0; //become invalid when there is ar[i] =0
    //     if(n==0) return 1;

    //     if(arr[n-1]>sum) return solve(arr,n-1,sum);

    //     return solve(arr,n-1,sum-arr[n-1]) + solve(arr,n-1,sum);
    // }
	// int perfectSum(int arr[], int n, int sum){
    //     return solve(arr,n,sum);
	// }



    //become invalid when there is ar[i] =0
    // int solve(int arr[],int n,int sum){
    //     if(sum==0) return 0; 
    //     if(n==0) return 1;
    //     if(arr[n-1]>sum) return solve(arr,n-1,sum);
    //     return solve(arr,n-1,sum-arr[n-1]) + solve(arr,n-1,sum);
    // }
	// int perfectSum(int arr[], int n, int sum){
    //     return solve(arr,n,sum);
	// }
	  
};

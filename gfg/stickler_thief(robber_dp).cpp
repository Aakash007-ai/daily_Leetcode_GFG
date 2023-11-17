#include<bits/stdc++.h>
using namespace std;

/*
    ok.....
    n= 5 , 6 5 5 7 4 // he has to theft such that no two consecutive get looted
    so we have to find max with choice so DP
    basic recursion

    so starting from last index, we can loot last index or not
    if not go to n-1, if yes go to n-2
    also if n<=0 return 0 no house left

    //boundary case if n==2 return max of 0, 1
    so assumption a solve function 
*/

//basic recursion
// int solve(int arr[],int n){
//     if(n<=0) return 0;    
//     if(n==1) return arr[n-1];
//     if(n==2) return max(arr[0],arr[1]);
//     return max(arr[n-1]+solve(arr,n-2),solve(arr,n-1));
// }
// //Function to find the maximum money the thief can get.
// int FindMaxSum(int arr[], int n){
//     if(n==1) return arr[0];
//     if(n==2) return max(arr[0],arr[1]);

//     return solve(arr,n);
// }

//segmentation fault for large input 100000 i.e. 1e5 passed 1110 cases 
    // int solve(int arr[],int n,vector<int> &dp){
    //     if(n<=0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     if(n==1) return dp[n]=arr[n-1];
    //     if(n==2) return dp[n]=max(arr[0],arr[1]);

    //     return dp[n]=max(arr[n-1]+solve(arr,n-2,dp),solve(arr,n-1,dp));
    // }
    // //Function to find the maximum money the thief can get.
    // int FindMaxSum(int arr[], int n){
    //     if(n==1) return arr[0];
    //     if(n==2) return max(arr[0],arr[1]);
    //     vector<int> dp(n+1,-1);
    //     return dp[n]=solve(arr,n,dp);
    // }

class Solution{
    public:
    int solve(int arr[],int n,vector<int> &dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n==1) return dp[n]=arr[n-1];
        if(n==2) return dp[n]=max(arr[0],arr[1]);

        return dp[n]=max(arr[n-1]+solve(arr,n-2,dp),solve(arr,n-1,dp));
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n){
   

        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);

        //we know we have elemetns to apply dp
        //initialization
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i==1) {dp[i]=arr[i-1];continue;}
            if(i==2) {dp[i]=max(arr[i-1],arr[i-2]);continue;}
            dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
        }

        return dp[n];
    }
};


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.FindMaxSum(arr,n);
}
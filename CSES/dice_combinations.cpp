#include<bits/stdc++.h>

using namespace std;

// int solve(int n,int i,int arr[]){
// int solve(int n,int i,vector<int> arr){
//     if(n==0){
//         cout<<" n is 0 --at i = "<<i<<" ";
//         return 1;
//     }
//     if(i==0) return 0; //no elements left in the array //we are following as no. of elements
//     if(arr[i-1]>n){
//         return solve(n,i-1,arr);
//     }
//     return solve(n-arr[i-1],i,arr)+solve(n,i-1,arr);
// }

// //recursion
// int solve(int n,int i){
//     if(n==0) return 1;
//     int count=0;
//     for(int j=1;j<=6;j++){
//         if(j<=n){
//             count += solve(n-j,i);
//         }
//     }
//     return count;
// }
// //only n changes here

// int main(){
//     int n;
//     cin>>n;
//     // int arr[6]={1,2,3,4,5,6}; //arr with coins
//     cout<<solve(n,6);
// }

int MOD = 1e9+7;
// recursion with memoization
int solve(int n,int i,vector<int> &dp){
    if(n==0) return 1;
    int count=0;

    if(dp[n-1] != -1) return dp[n-1];
    for(int j=1;j<=6;j++){
        if(j<=n){
            count += solve(n-j,i,dp);
        }
    }
    return dp[n-1]=count%MOD;
}

//only n changes here

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n,6,dp);
}
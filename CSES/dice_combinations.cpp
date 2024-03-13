#include<bits/stdc++.h>
using namespace std;

//brute force failed because of assumptiona

//learning think like dice 6 number out of 6 we can get any so traverse on all of them once and do unitl we get ans

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

// int main(){
//     int n;
//     cin>>n;
//     // int arr[6]={1,2,3,4,5,6}; //arr with coins
//     cout<<solve(n,6);
// }


// we got this algo via recursion we have 6 faces i.e 1 to 6 no.
// and we have sum as 6 so assuming all number can come so decrement no. and call for nested
//  so whenever we get our val==0 it means nothing to count and we got a sum return 1 to count


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

// //only n changes here so vector<int> dp(n+1);


int MOD = 1e9+7;
// // recursion with memoization
// int solve(int n,vector<int> &dp){
//     if(n==0) return 1;
//     int count=0;

//     if(dp[n-1] != -1) return dp[n-1]%MOD;
//     for(int j=1;j<=6;j++){
//         if(j<=n){
//             count += solve(n-j,dp)%MOD;
//         }
//         count=count%MOD;
//     }
//     return dp[n-1]=count%MOD;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<solve(n,dp);
// }

//top down

//first of all declaration of vector is different as earlier we pass -1 now we pass 0
// make a dp vector , do initialization of vector
// fill base cases
// convert recursion to for loop

// a for loop where j where j goes fron 1 to n (as we can get value of vector of next from previous)
// now as ususal calling of function to previous value changes to calling of previous filled valued

//
int solve(int n){
    if(n==0) return 1;
    vector<int> dp(n+1,0); //for we want in how many ways n can sum up witn no. 1 to 6 dp[0] means we want sum == 0 
    dp[0]=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=6;i++){
            if(j>=i){
                dp[j] += (dp[j-i]%MOD);
            }
            dp[j] %= MOD;
        }
    }
    return dp[n]%MOD;
}

int main(){
    int n;
    cin>>n;
    // vector<int> dp(n/+1,-1);
    cout<<solve(n);
}